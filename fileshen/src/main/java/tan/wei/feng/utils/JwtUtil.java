package tan.wei.feng.utils;

import java.lang.management.ManagementFactory;
import java.lang.management.MemoryUsage;
import java.nio.charset.Charset;
import java.util.Date;

import org.springframework.stereotype.Component;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.JwtBuilder;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;

/**
 * token生成和解析
 * @author 
 *
 */
@Component
public class JwtUtil {
	
	
	private static final String ROLES = "roles";
	
    private static String key = "fengshenme" ;
    //默认配置为一个小时
    private static long ttl = 3600000;

    /**
     * 生成JWT
     * @param id
     * @param subject
     * @return token
     */
    public String createJWT(String id, String subject, String roles) {
        /**
		 * setIssuedAt用于设置签发时间
		 * signWith用于设置签名秘钥
		 * setExpiration设置过期时间
		 * 自定义claims添加角色
		 */
        JwtBuilder builder = Jwts.builder().setId(id)
                .setSubject(subject)
                .setIssuedAt(new Date())
                .signWith(SignatureAlgorithm.HS256, key.getBytes(Charset.forName("utf-8")))
                .claim(ROLES, roles)
            	.setExpiration( new Date(System.currentTimeMillis() + ttl));
        return builder.compact();
    }
//    private static final Logger logger =  LoggerFactory.getLogger(JwtUtil.class);
	
    /**
     * 解析JWT
     * @param token
     * @return
     */
    public static Claims parseJWT(String token){
        return  Jwts.parser()
                .setSigningKey(key.getBytes(Charset.forName("utf-8")))
                .parseClaimsJws(token)
                .getBody();
    }
    
      
    /**
	 * 虚拟机的内存情况查询
	 * @return
	 */
	public String jvmMemory () {
		int byteToMb = 1024 * 1024 ;
		MemoryUsage memoryUsage = ManagementFactory.getMemoryMXBean().getHeapMemoryUsage(); //椎内存使用情况
		// 初始的总内存
		long totalMemorySize = memoryUsage.getInit()/byteToMb; 
		// 最大可用内存
	    long maxMemorySize = memoryUsage.getMax()/byteToMb; 
	    // 已使用的内存
	    long usedMemorySize = memoryUsage.getUsed()/byteToMb; 
		System.out.println(totalMemorySize + "mb");
		System.out.println(maxMemorySize + "mb");
		System.out.println(usedMemorySize + "mb");
		return null ;
	}
    
}