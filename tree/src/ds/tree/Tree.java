package ds.tree;

import ds.Node;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

import static java.util.Objects.isNull;

public enum  Tree {
    TREE;

    Node root;
    private List<Integer> elements = new ArrayList<>();

    void add(Integer data) {
        root = add(root, data);
    }

    private Node add(Node node, Integer data) {
        if (Objects.isNull(node)) {
            node = new Node(data);
            return node;
        }
        if (weight(node.left) < weight(node.right)) {
            node.left = add(node.left, data);
            return node;
        }
        node.right = add(node.right, data);
        return node;
    }

    int weight(Node node) {
        if (Objects.isNull(node)) {
            return 0;
        }
        return 1 + weight(node.left) + weight(node.right);
    }

    Integer get() {
        return root.data;
    }

    void print() {
        TreePrinter.printNode(root);
    }

    @Override
    public String toString() {
        toList(root);
        return Arrays.toString(elements.toArray());
    }

    private void toList(Node node) {
        if (node == null)
            return;
        elements.add(node.data);
        toList(node.left);
        toList(node.right);
    }


    Integer lca(Integer num1, Integer num2) {
        List<Node> pathToNum1 = new ArrayList<>();
        routeToNode(root, num1, pathToNum1);
        List<Node> pathToNum2 = new ArrayList<>();
        routeToNode(root, num2, pathToNum2);
        for (int i = 0; i < pathToNum1.size(); i++) {
            if (!pathToNum1.get(i).equals(pathToNum2.get(i))) {
                return pathToNum1.get(i - 1).data;
            }
        }
        return -1;
    }

    void routeToNode(Node node, Integer num1, List<Node> path) {
        if (!isNull(node)) {
            path.add(node);
        }
        if (node.data.equals(num1)) {
            return;
        }
        // {10,30,50,90}
        if (!isNull(node.left)) {
            routeToNode(node.left, num1, path);
        }
        if (!isNull(node.right)) {
            routeToNode(node.right, num1, path);
        } else {
            path.remove(path.size() - 1);
        }
    }
}