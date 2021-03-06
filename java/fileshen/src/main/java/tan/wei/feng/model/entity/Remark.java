package tan.wei.feng.model.entity;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 评论模型
 * @author 1015956962@163.com
 *
 */
@Entity
@Table(name="tb_remark")
public @Data class Remark implements Serializable{
	
	
	private static final long serialVersionUID = -4676388333967134772L;
	
	/**
	 * id中有评论创建时间
	 */
	@Id 
	private Long id ;
	/**
	 * 文章id
	 */
	private Long articleId;
	/**
	 * 用户id
	 */
	private Long userId;
	/**
	 * 用户名
	 */
	private String userName;
	/**
	 *  评论内容
	 */
	private String content;
	
	private Integer total;
}
