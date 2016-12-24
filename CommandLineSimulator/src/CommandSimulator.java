import java.io.*;
import java.util.*;


public class CommandSimulator {

	class TreeNode{
		FileDescriptor information;
		TreeNode parent;
		ArrayList<TreeNode> children;
		
		TreeNode(){
			information = new FileDescriptor();
			parent = null;
			children = new ArrayList<>();
			
		}
		
		TreeNode(FileDescriptor information, TreeNode parent ){
			this.information = information;
			this.parent = parent;
			children = new ArrayList<>();
			
		}
		
		public void insert(TreeNode child){
			children.add(child);
		}
		public void remove(TreeNode child){
			children.remove(child);
		}
		
		public String getFileName(){
			return information.getFilename();
		}
		
		public void setFileName(String name){
			information.setFilename(name);
		}
		
		public boolean isFolder(){
			return information.isDIR();
		}
		
		public String displayContent(){
			return information.getContent();
		}
		
		//change parent
		//sort children
		
		
		
		
	}
	
	class FileDescriptor{
		private String content;
		private String filename;
		private boolean isDIR;
		
		FileDescriptor(){
			content = "";
			filename = "root";
			isDIR = true;
		}
		
		FileDescriptor(String filename, boolean isDIR ){
			this.filename = filename;
			this.isDIR = isDIR;
			
		}
		
		void appendContent(String newContent){
			content = content + newContent;
		}
		
		public String getFilename() {
			return filename;
		}

		public void setFilename(String filename) {
			this.filename = filename;
		}

		public String getContent() {
			return content;
		}

		public boolean isDIR() {
			return isDIR;
		}

		void display(){
			System.out.println("Name : " + filename);
			System.out.println("File type: ");
			if(isDIR){
				System.out.println("Folder");
			}else{
				System.out.println("Text file");
			}
			
			
		}
		
	}
	
	class Tree{
		TreeNode root;
		
		Tree(){
			
		}
		//insert
		//delete
		//search
		
	}
	
	
	
	
}
