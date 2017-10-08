import java.util.*;
class Heap {
	private int sizeToIncrement = 10;
	private Node data[] = new Node[10];
	private int size = 0;
	public static void main(String[] args) {
        Heap x = new Heap();
        x.enqueue(1, 4);
        System.out.println(x);
        x.enqueue(1, 2);
        System.out.println(x);
        x.enqueue(1, 3);
        System.out.println(x);
        x.enqueue(1, 6);
        System.out.println(x);
        // x.dequeue();
        // System.out.println(x);
        // x.dequeue();
        // System.out.println(x);
        // x.dequeue();
        // x.dequeue();
        // x.dequeue();
        // System.out.println(x);
        // System.out.println(5/2);
    }

    private int getParent(int index){
    	return (index - 1)/2;
    }

    public boolean enqueue(Object element, int priority){
        int currentIndex = size;
        data[size++] = new Node(element, priority);
        int parent = getParent(currentIndex)
        while (parent != 0) {
            if (priority < data[parent].priority){
                swap(currentIndex, parent);
                currentIndex = parent;
            }
        }
    	return true;
    }

    private void swap(int index1, int index2){
        Node temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    public Object dequeue(){
    	Node temp = data[0];
    	data[0] = data[--size];
    	return temp;
    }

    public String toString(){
    	return Arrays.toString(data);
    }
}