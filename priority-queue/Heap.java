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

    private boolean hasParent(int index) {
        return getParent(index) >= 0;
    }

    private boolean hasLeftChild(int index){
        return getLeftIndex(index) < size;
    }

    private boolean hasRightChild(){
        return getRightIndex(index) < size;
    }

    private int getLeftIndex(int index) {
        return 2 * index + 1;
    }

    private int getRightIndex(int index) {
        return 2 * index + 2;
    }

    public boolean enqueue(Object element, int priority){
        int currentIndex = size;
        data[size++] = new Node(element, priority);
        while (parent != 0) {
            int parent = getParent(currentIndex);
            if (priority < data[parent--].priority){
                swap(currentIndex, parent);
                currentIndex = parent;
            } else {}
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
        int currentIndex = 0;

        while(hasLeftChild(currentIndex)){
            if (data[currentIndex].priority < data[getLeftIndex(currentIndex)].priority){
                break;
            }
            int indexToSwap = getLeftIndex(currentIndex);
            if (hasRightChild() && data[getLeftIndex(currentIndex)].priority > data[getRightIndex(currentIndex)].priority) {
                indexToSwap = getRightIndex(currentIndex);
            }
            swap(currentIndex, indexToSwap);
            currentIndex = indexToSwap;
        }
    	return temp;
    }

    public String toString(){
    	return Arrays.toString(data);
    }
}