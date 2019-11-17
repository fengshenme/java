package cn.tan.upload.utils;

import java.util.Date;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.data.redis.core.RedisTemplate;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.ExpiredJwtException;
import io.jsonwebtoken.JwtBuilder;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import io.jsonwebtoken.SignatureException;

/**
 * Created by Administrator on 2018/4/11.
 */
@ConfigurationProperties("jwt.config")
public class JwtUtil {
	
	private static final Logger logger = LoggerFactory.getLogger(JwtUtil.class);
	
    private String key ;
    //一个小时
    private long ttl ;

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public long getTtl() {
        return ttl;
    }

    public void setTtl(long ttl) {
        this.ttl = ttl;
    }

    /**
     * 生成JWT
     *
     * @param id
     * @param subject
     * @return
     */
    public String createJWT(String id, String subject, String roles) {
    	// 当前时间
        long nowMillis = System.currentTimeMillis();
        Date now = new Date(nowMillis);
        /**
		 * setIssuedAt用于设置签发时间
		 * signWith用于设置签名秘钥
		 * setExpiration设置过期时间
		 * 自定义claims添加角色
		 */
        JwtBuilder builder = Jwts.builder().setId(id)
                .setSubject(subject)
                .setIssuedAt(now)
                .signWith(SignatureAlgorithm.HS256, key).claim(ROLES, roles);
        if (ttl > 0) {
            builder.setExpiration( new Date( nowMillis + ttl));
        }
        return builder.compact();
    }

    /**
     * 解析JWT
     * @param jwtStr
     * @return
     */
    public Claims parseJWT(String jwtStr){
        return  Jwts.parser()
                .setSigningKey(key)
                .parseClaimsJws(jwtStr)
                .getBody();
    }
    
    private static final String JWTERROR = "error";  
    private static final String ROLES = "roles"; 
    @Autowired
	private RedisTemplate<String,String> redisTemplate;
    /**
     * 验证权限设置角色
     * @param request
     * @param response
     * @param token
     */
    public void verifyJWT(HttpServletRequest request,HttpServletResponse response,String token) {
    	try {
			// 对令牌进行验证
			Claims claims = parseJWT(token);
			if (redisTemplate.opsForValue().get("userid_"+claims.getId()) != null) {
				//如果是管理员
				if("admin".equals(claims.get(ROLES))){
					request.setAttribute("admin_claims", claims);
				}
				//如果是用户
				if("user".equals(claims.get(ROLES))){
					request.setAttribute("user_claims", claims);
				}
			}
		} catch (ExpiredJwtException e) {
			logger.info(e.getMessage(),"token已过期 {}");
			request.setAttribute(JWTERROR, "token已过期");
		} catch (SignatureException e) {
			logger.info(e.getMessage(),"签名校验失败 {}");
			request.setAttribute(JWTERROR, "签名校验失败");
		} catch (Exception e) {
			logger.info(e.getMessage(),"其它错误 {}");
			request.setAttribute(JWTERROR, "请重新登录");
		}
    }
    
}