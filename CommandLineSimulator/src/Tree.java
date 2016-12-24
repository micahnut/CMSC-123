
public class Tree {
	TreeNode root;
	// TreeNode current;

	public Tree(TreeNode n) {
		this.root = n;
		// this.current = root;
	}

	// public boolean insert(TreeNode node){
	// boolean found = false;
	// for(TreeNode child : current.children){
	// if(child.fileDescriptor.getFilename().equals(node.fileDescriptor.getFilename())
	// && child.fileDescriptor.isDIR == node.fileDescriptor.isDIR)
	// found = true;
	// }
	// if(!found){
	// current.getChildren().add(node);
	// node.parent = current;
	// }
	// return true;
	// }
	//
	// public boolean remove(TreeNode node){
	// for(TreeNode child: current.children){
	// if(child.fileDescriptor.getFilename().equals(node.fileDescriptor.getFilename())){
	// current.getChildren().remove(child);
	// return true;
	// }
	// }
	// return false;
	//
	// }

	 public TreeNode search(String fileName, TreeNode node){
		 if(node.getFileName().equals(fileName)){
			 return node;
		 }
		 else{
			 System.out.println("current: "+ node.getFileName());
			 System.out.println("node children size: "+ node.children.size());
			 for(int i =0; i<node.children.size();i++){
				 return search(fileName, node.children.get(i));
			 }
			 
		 }
		 return null;
	 }

}
