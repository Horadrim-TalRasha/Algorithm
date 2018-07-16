class BinaryTreeNode{
	int value;
	BinaryTreeNode leftNode,rightNode;
}
public class rebuild_binary_tree {
	static BinaryTreeNode rebuild(int[] preorder,int[] inorder){
		BinaryTreeNode root = rebuild(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
		return root;
	}
	//参数包含子遍历，以及遍历开始和结束的位置
	static BinaryTreeNode rebuild(int[] preorder,int startPre,int endPre,int[] inorder,int startIn,int endIn){
		if( startPre > endPre || startIn > endIn || preorder.length != inorder.length){
			return null;
		}
		boolean haveRoot = false;
		//前序第一个数为根节点
		BinaryTreeNode root = new BinaryTreeNode();
		for(int i=startIn;i<=endIn;i++){
			//找根节点
			if(inorder[i] == preorder[startPre]){
				haveRoot = true;
				root.value = preorder[startPre];
				root.leftNode = rebuild(preorder, startPre+1, startPre+1+(i-startIn), inorder, startIn, i-1);
				root.rightNode = rebuild(preorder, i-startIn+startPre+1, endPre, inorder, i+1, endIn);
				//用数组索引比较复杂，另一种用复制数组的方法好理解。
				//root.leftNode = rebuild(Arrays.copyOfRange(preorder, 1, i+1), Arrays.copyOfRange(inorder, 0, i));
				//root.rightNode = rebuild(Arrays.copyOfRange(preorder, i+1, preorder.length), Arrays.copyOfRange(inorder, i+1,inorder.length));
			}
		}
		if(!haveRoot){
			System.out.println("没有找到根节点");
			return null;
		}
		return root;
	}
	//后序遍历树
	static void postorder(BinaryTreeNode root){
		if(root == null){
			System.out.println("根节点为空");
		}
		if(root.leftNode != null){
			postorder(root.leftNode);
		}
		if(root.rightNode != null){
			postorder(root.rightNode);
		}
		System.out.println(root.value);
	}
	public static void main(String[] args) {
		int[] preorder = {1,2,4,7,3,5,6,8};
		int[] inorder = {4,7,2,1,5,3,8,6};
		postorder(rebuild(preorder, inorder));
	}
}
