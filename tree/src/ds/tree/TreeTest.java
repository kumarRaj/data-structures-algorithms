package ds.tree;

import ds.Node;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class TreeTest {

    @Test
    public void addToRoot() {
        Tree tree = new Tree();
        tree.add(5);

        assertEquals(tree.get(), new Integer(5));
    }


    @Test
    public void testWeight() {
        Tree tree = new Tree();
        for (int i = 0; i < 10; i++) {
            tree.add(ThreadLocalRandom.current().nextInt(1, 100));
        }
        tree.print();

        System.out.println(tree.weight(tree.root.left));
        System.out.println(tree.weight(tree.root.right));
    }

    @Test
    public void testLca() {
        Tree tree = new Tree();
        Integer data[] = {10, 20, 30, 40, 50, 60, 71, 80, 90, 91};
        for (int i = 0; i < 10; i++) {
            tree.add(data[i]);
        }
        tree.print();
        assertEquals(new Integer(30), tree.lca(71, 90));
    }

    @Test
    public void testPathToNode() {
        Tree tree = new Tree();
        Integer data[] = {10, 20, 30, 40, 50, 60, 71, 80, 90, 91};
        for (int i = 0; i < 10; i++) {
            tree.add(data[i]);
        }
        List emptyList = Collections.EMPTY_LIST;
        tree.print();
        Integer expectedResult[] = {10, 30, 71};
        ArrayList<Node> path = new ArrayList<>();
        tree.routeToNode(tree.root, 90, path);
        assertArrayEquals(expectedResult, path.stream().map((z -> z.data)).toArray());
    }
}