package tan.wei.feng.controller;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.MalformedJwtException;
import tan.wei.feng.entity.Result;
import tan.wei.feng.entity.StatusCode;
import tan.wei.feng.service.create.FileSaveService;
import tan.wei.feng.service.delete.FileDeleteService;
import tan.wei.feng.service.read.FileDownService;
import tan.wei.feng.service.read.FileFindService;
import tan.wei.feng.utils.FileDirUtils;

/**
 * 文件控制层
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/api")
public class FileController {
	
	private static final Logger logger =  LoggerFactory.getLogger(FileController.class);
	
	@Autowired
	private HttpServletRequest request = null;
	@Autowired
	private FileDownService fileDownService = null;
	@Autowired
	private FileFindService fileFindService = null;
	@Autowired
	private FileSaveService fileSaveService = null;
	@Autowired
	private FileDeleteService fileDeleteService = null;
	
	
	@Value("${storessd.filepath}")
	private String datapath;
	
	/**
	 * 获取用户下的文件列表
	 * @return
	 */
	@GetMapping(value = "/fileList/{fileType}")
	public Result fileUrlList(@PathVariable String fileType){
		
		try {
			Claims claims = (Claims) request.getAttribute("user_claims");
			logger.info(claims.getId());
			if(claims.getId()==null || "".equals(claims.getId().trim())){
				return new Result(StatusCode.ERROR);
			}
			return new Result(StatusCode.OK,"查询成功",fileFindService.findByfileid(claims.getId(),fileType));
		}catch (Exception e) {
			logger.info(e.getMessage());
			return new Result(StatusCode.ERROR);
		}
		
	}
	
	/**
	 * 获取用户下的分页文件列表
	 * @return
	 */
	@GetMapping(value = "/filePageList/{fileType}")
	public Result fetchList(@RequestParam Map<String,String> map,@PathVariable String fileType){
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims == null){
			return new Result(StatusCode.ERROR,"请登录在查询");
		}
		if(claims.getId() != null && !"".equals(claims.getId().trim())){
			return new Result(StatusCode.OK,"查询成功",fileFindService.findByfileidPage(claims.getId(),fileType,map));
		}
		return new Result(StatusCode.ERROR,"请上传文件");
	}
	
	
	/**
	 * 文件下载
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/fileDownload/{filecode}")
	public ResponseEntity<?> fileDownload(@PathVariable String filecode) throws IOException {  
		Claims claims=(Claims) request.getAttribute("user_claims");
		logger.info(claims.getId());
		if(claims==null || "".equals(claims.getId())){
			Result result = new Result("请登录在下载"); 
			// 也可以放置页面,图片等
			return new ResponseEntity<Result>(result, HttpStatus.UNAUTHORIZED);
		} else {
	        return fileDownService.fileDownload(filecode);
		}
	}
	
	
	/**
	 * 文件保存
	 * @param <file>
	 * @param file
	 * @return
	 * 
	 */
	@PostMapping(value = "/uploadFile")
	public Result fileSave(@RequestParam("file") MultipartFile file){
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			return new Result(StatusCode.ERROR,"请登录在上传");
		}  
		if(!file.isEmpty()){
			// 递归次数
			int ia = 3;
			String filePath = FileDirUtils.dirFile(datapath,file.getOriginalFilename(),ia) ;
			//转存文件
	        try {
	            file.transferTo(new File(filePath));
	        } catch (Exception e) {
	        	File filea = new File(filePath);
	        	filea.delete();
	            return new Result(StatusCode.ERROR,e.getMessage());
	        }
	        if(fileSaveService.addFile(filePath,claims.getId())) {
				return new Result(StatusCode.OK,"上传成功");
			} 
	     }
		return new Result(StatusCode.ERROR,"上传失败重新上传");
	}
		
	/**
	 * 文件删除
	 * @param fileId
	 * @return
	 */
	@DeleteMapping(value = "/delFile/{fileId}")
	public  Result delFile(@PathVariable String fileId) {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			return new Result(StatusCode.ERROR,"请登录在下载");
		}else {
			if(fileDeleteService.delfile(Long.parseLong(fileId))) {
				return new Result(StatusCode.OK,"删除成功");
			} else {
				return new Result(StatusCode.ERROR,"删除失败");
			}
		}
	}

}
