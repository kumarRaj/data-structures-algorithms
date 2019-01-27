package ds;

import java.util.*;

import static java.util.Objects.isNull;

class BinaryTreeNode {
    int leftSubTreeSize;
    int rightSubTreeSize;
    Integer data;
    BinaryTreeNode left;
    BinaryTreeNode right;

}

public class BinaryTree {
    private BinaryTreeNode tree = new BinaryTreeNode();
    public void add(Integer data){
        add(tree, data);
    }

    private void add(BinaryTreeNode node, Integer data) {
        if (null == node.data){
            node.data = data;
            return;
        }
        if (node.leftSubTreeSize <= node.rightSubTreeSize){
            node.leftSubTreeSize++;
            add(node.left, data);
            return;
        }
        node.rightSubTreeSize++;
        add(node.right, data);
    }

    public Map<Integer, List<BinaryTreeNode>> horizontalView(){
        HashMap<Integer, List<BinaryTreeNode>> treeView = new HashMap<>();
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        if(null == tree.data){
            return treeView;
        }
        queue.add(tree);
        queue.add(null);
        while (queue.size() > 1){
            BinaryTreeNode node = queue.remove();
            if (isNull(node)){
                queue.add(node);
            }
            if(isNull(node.left.data))
                queue.add(node.left);
            if(isNull(node.right.data))
                queue.add(node.right);
        }

        return new HashMap<>();
    }
}