import java.util.ArrayList;

public class TreeNode {

	FileDescriptor fileDescriptor;
	TreeNode parent;
	ArrayList<TreeNode> children;

	TreeNode() {
		fileDescriptor = new FileDescriptor();
		parent = null;
		children = new ArrayList<>();

	}

	TreeNode(FileDescriptor information, TreeNode parent) {
		this.fileDescriptor = information;
		this.parent = parent;
		children = new ArrayList<>();

		if (parent != null) { // insert
			parent.children.add(this);
		}

	}

	// public TreeNode find(FileDescriptor info){
	// if(this.information.equals(info)){
	// return this;
	// }
	// else{
	// for(TreeNode child : children){
	// TreeNode found = child.find(info);
	// if(found != null){
	// return found;
	// }
	// }
	// return null;
	// }
	// }
	
	public void insert(TreeNode node){
		node.children.add(this);
		this.parent = node;
	}
	public void remove() {
		parent.children.remove(this);
		this.parent = null;
	}

	public String getFileName() {
		return fileDescriptor.getFilename();
	}

	public void setFileName(String name) {
		fileDescriptor.setFilename(name);
	}

	public boolean isFolder() {
		return fileDescriptor.isDIR();
	}

	public String displayContent() {
		return fileDescriptor.getContent();
	}

	public TreeNode getParent() {
		return parent;
	}

	public void setParent(TreeNode parent) {
		this.parent = parent;
	}

	public ArrayList<TreeNode> getChildren() {
		return children;
	}

	public FileDescriptor getFileDescriptor() {
		return fileDescriptor;
	}

}
