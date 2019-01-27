package ds;

import ds.BTreePrinter;
import ds.BinarySearchTree;
import ds.Node;

import java.util.List;
import java.util.Map;
import java.util.Random;

public class TreeMain {
    public static void main(String[] args) {
        BinarySearchTree binaryTree = newRandomTree();
//        binaryTree.add(4);
//        binaryTree.add(3);
//        binaryTree.add(5);
//        binaryTree.add(1);
//        binaryTree.add(2);

        Map<Integer, List<Node>> horizontalView = binaryTree.horizontalView();
        Map<Integer, List<Node>> verticalView = binaryTree.verticalView();
        // System.out.println(horizontalView);
        System.out.println(verticalView);
        BTreePrinter.printNode(binaryTree.getHead());
    }

    private static BinarySearchTree newRandomTree() {
        BinarySearchTree binaryTree = new BinarySearchTree();
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            binaryTree.add(random.nextInt(100));
        }
        return binaryTree;
    }
}
