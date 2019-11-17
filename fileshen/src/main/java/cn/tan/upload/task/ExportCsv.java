package cn.tan.upload.task;

import java.io.IOException;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import cn.tan.upload.entity.WeiBoSearch;
import cn.tan.upload.entity.WeiboFollow;
import cn.tan.upload.service.WeiBoSearchService;
import cn.tan.upload.utils.ReadWriterFileUtils;

/**
 * weibo导出csv文件,导出编码为GB18030
 * @author 10159
 *
 */
@Component
public class ExportCsv {
	
	private final WeiBoSearchService weiBoSearchService ;
	
	@Autowired
	public ExportCsv( WeiBoSearchService weiBoSearchService) {
		this.weiBoSearchService = weiBoSearchService;
	}
	/**
	 * 写入内容
	 * @throws IOException
	 */
	//@Scheduled(cron= "30 27 * * * ?")
	public void saveCsv() throws IOException {
		List<WeiBoSearch> weibolist= weiBoSearchService.findAll();
		String csvheader = "userid`content`addtime`nickname`weibourl`labels`employphone";
	    String savefile = "H:/test.csv";
	    //写入头部
	    ReadWriterFileUtils.writer(csvheader,savefile);
	    // 写入内容
	    for (WeiBoSearch weiBo : weibolist) {
	    	ReadWriterFileUtils.writer(weiBo.toCsv(),savefile);
		}
	}
	
	/**
	 * 文件以gb19030编码写入
	 * @throws IOException
	 */
	//@Scheduled(cron = "30 47 * * * ?")
	public void saveFollowCsv() throws IOException {
		List<WeiboFollow> findFollowAll = weiBoSearchService.findFollowAll();
		String csvheader = "id`userid`friendid`userurl`friendurl`friendinfo`sex`nickname`followfans`addtime";
		String savefile = "H:/followfriends00.csv";
	    //写入头部ㄅ
	    ReadWriterFileUtils.writer(csvheader,savefile);
	    // 写入内容
	    for (WeiboFollow weiboFoll : findFollowAll) {
	    	ReadWriterFileUtils.writer(weiboFoll.toCsv(),savefile);
		}
	}
	
}













