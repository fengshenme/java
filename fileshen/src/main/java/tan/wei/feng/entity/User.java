package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 用户模型
 * @author 锋什么
 *
 */
@Entity
@Table(name="tb_user")
public @Data class User implements Serializable{
	
	private static final long serialVersionUID = -225093095725197964L;


	@Id
	private Long id;
	
	private String password;
	/**
	 *  昵称
	 */
	private String nickname;
	
	private String mobile ;

	private String email;
	
	private String address;
	
	private int sex ;
	
	@Column(name="update_time")
	private Date updateTime;
	
	
}
