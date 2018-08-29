import java.util.Objects;

class Node {
    public Integer data;
    public Node left;
    public Node right;

    Node() {

    }

    Node(Integer data) {
        this.data = data;
    }
}

public class BinaryTree {
    static Node tree = new Node();

    public BinaryTree() {
        tree.left = new Node();
        tree.right = new Node();
    }

    public static void main(String[] args) {
        add(tree, 4);
        add(tree, 3);
        add(tree, 5);
        add(tree, 1);
        add(tree, 2);
        System.out.println("Inorder --");
        inOrder(tree);
        System.out.println("Pre order --");
        preOrder(tree);
        System.out.println("Post order --");
        postOrder(tree);
    }

    static void add(Node node, Integer data) {
        if (Objects.isNull(node.data)) {
            node.data = data;
            node.left = new Node();
            node.right = new Node();
            return;
        }
        if (data <= node.data) {
            add(node.left, data);
            return;
        }
        add(node.right, data);
        //   4
        //  3 5
        // 1
        //  2
    }

    static void inOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            inOrder(node.left);
            System.out.println(node.data);
            inOrder(node.right);
        }
    }

    static void preOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            System.out.println(node.data);
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    static void postOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.println(node.data);
        }
    }

}