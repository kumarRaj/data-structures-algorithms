package ds;

import java.util.*;
import java.util.stream.Collectors;

class Node {
    Integer data;
    Node left;
    Node right;

    Node() {

    }

    Node(Integer data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return String.valueOf(data);
    }
}

class BinaryTree {
    private Node tree = new Node();
    private int maxLengthOfLevel;

    public Node getHead() {
        return tree;
    }

    BinaryTree() {
        tree.left = new Node();
        tree.right = new Node();
    }

    void add(Integer data) {
        add(tree, data);
    }

    private void add(Node node, Integer data) {
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

    private void inOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            inOrder(node.left);
            System.out.println(node.data);
            inOrder(node.right);
        }
    }

    private void preOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            System.out.println(node.data);
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    private void postOrder(Node node) {
        if (!Objects.isNull(node.data)) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.println(node.data);
        }
    }

    Map<Integer, List<Node>> verticalView(){
        HashMap<Integer, List<Node>> map = new HashMap<>();
        verticalView(map, 0, tree);
        return map;
    }

    private void verticalView(Map<Integer, List<Node>> map, Integer distance, Node node) {
        if(null == node.data){
            return;
        }
        if (null == map.get(distance)){
            map.put(distance, new ArrayList<>());
            map.get(distance).add(node);
        } else {
            map.get(distance).add(node);
        }
        verticalView(map, distance - 1, node.left);
        verticalView(map, distance + 1, node.right);
    }


    Map<Integer, List<Node>> horizontalView() {
        Integer count = 0;
        Map<Integer, List<Node>> treeLevels = new TreeMap<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(tree);
        queue.add(null);
        while (queue.size() > 1) {
            if (queue.peek() == null) {
                if (treeLevels.get(count).size() > maxLengthOfLevel) {
                    maxLengthOfLevel = treeLevels.get(count).size();
                }
                ++count;
                queue.add(queue.remove());
                continue;
            }
            Node el = queue.remove();
            if (treeLevels.get(count) != null) {
                treeLevels.get(count).add(el);
            } else {

                treeLevels.put(count, new ArrayList<>());
                treeLevels.get(count).add(el);
            }
            if (el.left.data != null) {
                queue.add(el.left);
            }
            if (el.right.data != null) {
                queue.add(el.right);
            }
        }
        return treeLevels;
    }

    @Override
    public String toString() {
        Map<Integer, List<Node>> integerListMap = horizontalView();
        StringBuilder stringBuilder = new StringBuilder();
        for (List<Node> nodes : integerListMap.values()) {
            List<String> nums = nodes.stream().map(node -> String.valueOf(node.data)).collect(Collectors.toList());
            String[] spaces = new String[maxLengthOfLevel - nums.size() + 1];
            Arrays.fill(spaces, "");
            String line = String.join("\t", nums);
            stringBuilder.append(String.join("\t", spaces)).append(line).append("\n");
        }
        return stringBuilder.toString();
    }
}

//0 -> [90]
//1 -> [50,150]
//2 -> [20,80,110,160]
//3 -> [10,40,100]
//             90
//         50              150
//     20      80    110     160
// 10       40     100
//     30      45



