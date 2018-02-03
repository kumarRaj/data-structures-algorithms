// TODO: WIP Doesn't work now
import java.util.Arrays;

public class Heap {
	int data[] = new int[20];
	int size;
	private int getLeftChild(int index){
		return data[getLeftChildIndex(index)];
	}
	private int getRightChild(int index){
		return data[getRightChildIndex(index)];
	}
	private int getParent(int index){
		return data[getParentIndex(index)];
	}

	private boolean hasChildren(int index){
		return getLeftChildIndex(index) < size;
	}

	private int getLeftChildIndex(int index){
		return (2 * index) + 1;
	}
	private int getRightChildIndex(int index){
		return (2 * index) + 2;
	}
	private int getParentIndex(int index){
		return (index - 2)/2;
	}

	private void swap(int index1, int index2){
		int temp = data[index1];
		data[index1] = data[index2];
		data[index2] = temp;
	}

	private void heapifyDown(){
		int index = 0;
		int smallerChildIndex = getLeftChild(index) > getRightChild(index) 
		? getLeftChildIndex(index) : getRightChildIndex(index);
		while(index < size){
			if (data[index] > data[smallerChildIndex]){
				swap(index, smallerChildIndex);
				index = smallerChildIndex;
			}
		}
	}

	private void heapifyUp(){
		int index = size - 1;
		while (index > 0) {
			if (data[index] < getParent(index)){
				swap(index, getParentIndex(index));
				index = getParentIndex(index);
			} else break;
		}
	}

	public void printHeap() {
		System.out.println(Arrays.toString(data));
	}

	public int pop(){
		if (size != 0){
			int temp = data[0];
			data[0] = data[--size];
			heapifyDown();
			return temp;
		}
		return -1;
	}

	public int push(int element){
		data[size++] = element;
		heapifyUp();
		return element;
	}

	public static void main(String[] args) {
		Heap x = new Heap();
		x.push(4);
		x.push(3);
		x.push(7);

		x.printHeap();

		x.pop();

		x.printHeap();
	}
}
