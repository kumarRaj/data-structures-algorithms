package ds;

import java.util.List;
import java.util.Map;
import java.util.Random;

/**
 * Copyright 2018 Jubilant FoodWorks Limited . All Rights Reserved.
 * Jubilant FoodWorks PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

public class TreeMain {
    public static void main(String[] args) {
        BinaryTree binaryTree = newRandomTree();
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

    private static BinaryTree newRandomTree() {
        BinaryTree binaryTree = new BinaryTree();
        Random random = new Random();
        for (int i = 0; i < 6; i++) {
            binaryTree.add(random.nextInt(400));
        }
        return binaryTree;
    }
}
