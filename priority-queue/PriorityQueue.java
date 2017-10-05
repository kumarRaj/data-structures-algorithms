import java.util.*;
import java.lang.*;
class Node{
    Object data;
    int priority;

    public Node(Object d, int p){
        data = d;
        priority = p;
    }

    public String toString(){
        return data.toString() + "  " + priority;
    }
}

class PriorityQueue {

    private LinkedList<Node> l = new LinkedList();

    public static void main(String[] args) {
        PriorityQueue x = new PriorityQueue();
        x.enqueue(5, 1);
        x.enqueue(15, 3);
        x.enqueue(1, 2);
        x.enqueue(23, 6);
        System.out.println(x);
        x.dequeue();
        x.dequeue();
        System.out.println(x);
        x.dequeue();
        x.dequeue();
        x.dequeue();
        System.out.println(x);
    }

    public boolean enqueue(Object element, int priority){
        Node nodeToAdd = new Node(element, priority);
        if (l.size() == 0){
            l.add(nodeToAdd);
            return true;
        }
        int index = 0;
        while (index < l.size()) {
            if (priority <= l.get(index).priority){
                l.add(index, nodeToAdd);
                break;
            }
            index++;
        }

        if (index == l.size()){
            l.add(nodeToAdd);
        }
        return true;
    }

    public Object dequeue(){
        if (l.size() == 0){
            return Optional.empty();
        }
        return Optional.of(l.remove());
    }


    public PriorityQueue(){

    }

    public String toString(){
        return l.toString();
    }
}