package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * 文章实体类
 * @author Administrator
 *
 */
@Entity
@Table(name="tb_article")
public class Article implements Serializable{
	
    private static final long serialVersionUID = 1L;

	@Id
	private String id;//ID
	 
	private String columnid;//专栏ID
	private String userid;//用户ID
	private String title;//标题
	private String content;//文章正文
	private Date createtime;//发表日期
	private Integer visits;//浏览量
	private Integer thumbup;//点赞数
	private Integer comment;//评论数
	private String url;//URL
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getColumnid() {
		return columnid;
	}
	public void setColumnid(String columnid) {
		this.columnid = columnid;
	}
	public String getUserid() {
		return userid;
	}
	public void setUserid(String userid) {
		this.userid = userid;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public java.util.Date getCreatetime() {
		return createtime;
	}
	public void setCreatetime(java.util.Date createtime) {
		this.createtime = createtime;
	}
	public Integer getVisits() {
		return visits;
	}
	public void setVisits(Integer visits) {
		this.visits = visits;
	}
	public Integer getThumbup() {
		return thumbup;
	}
	public void setThumbup(Integer thumbup) {
		this.thumbup = thumbup;
	}
	public Integer getComment() {
		return comment;
	}
	public void setComment(Integer comment) {
		this.comment = comment;
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}

}
