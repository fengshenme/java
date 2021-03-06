package tan.wei.feng.task;

import java.io.File;
import java.io.IOException;
import java.util.Date;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.model.entity.WeiBoSearch;
import tan.wei.feng.model.service.WeiBoSearchService;

/**
 * 处理搜索结果页面
 * @author 1015956962@163.com
 *
 */
@Component
public class ImportFile {
	
	private static final Logger logger = LoggerFactory.getLogger(ImportFile.class);
	
	@Autowired
	private WeiBoSearchService weiBoSearchService ;
	
	/**
	* 处理搜索结果页面
	 * @throws IOException
	 * @Scheduled(cron= "30 12 * * * ?") 
	*/
	public void recommendTask() throws IOException{
		
	    File file = new File("H:/文件/weibo");
	    File[] tempList = file.listFiles();
	    for (File input : tempList) {
	    	if(input.isFile() ) {
	    		Document doc = Jsoup.parse(input, "UTF-8");
	    		Elements content = doc.getElementById("pl_feed_main").select("div.content");
	    		for (Element element : content) {
	    			WeiBoSearch weiBoSearch = new WeiBoSearch();
	    			String url = element.select("a.name").attr("href");
	    			String nickname = element.select("a.name").attr("nick-name");
	    			String contenta = element.select("p.txt").text();
	    			String userid = url.substring(18, 28);
	    			String employphone =element.select("div.content").select("p.from").text();
	    			weiBoSearch.setNickname(nickname);
	    			weiBoSearch.setContent(contenta);
	    			weiBoSearch.setWeibourl(url.substring(0, 28));
	    			weiBoSearch.setUserid(userid);
	    			weiBoSearch.setEmployphone(employphone);
	    			weiBoSearch.setAddtime(new Date());
	    			logger.info(weiBoSearch.toString());
	    			weiBoSearchService.save(weiBoSearch);
	    		}
	    	}  
		}
	}
	
}
