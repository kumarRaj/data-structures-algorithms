// TODO: WIP Doesn't work now
import java.lang.Math;

class Node{
	public int data = -999;
	public Node next;
	public Node previous;
}

public class LinkedListSort {
	public static void main(String[] args) {
		Node head = new Node();
		Node temp = head;
		for (int i = 0;i < 5 ;i+=1) {
			temp.data = (int)(Math.random() * 100);
			temp.next = new Node();
			temp.next.previous = temp;
			temp = temp.next;
		}

		temp = head;
		while (temp.data != -999) {
			System.out.println(temp.data);
			temp = temp.next;
		}
/* 
{62,45,21,56,87,23};
{62,62,21,56,87,23};
{45,62,21,56,87,23};
{45,62,62,56,87,23};
{45,45,62,56,87,23};
{21,45,62,56,87,23};
{21,45,62,62,87,23};
{21,45,56,62,87,23};
{21,45,56,62,62,87};
{21,45,56,56,62,87};
{21,23,45,56,62,87};
*/
		temp = head.next;
		while (temp.next.data != -999) {
			int currentData = temp.next.data;
			Node previousNode = temp.previous;
			while (previousNode != null && previousNode.data > currentData) {
				previousNode.next.data = previousNode.data;
				previousNode = previousNode.previous;
			}
			previousNode.next.data = currentData;
		}

		temp = head;
		while (temp.data != -999) {
			System.out.println(temp.data);
			temp = temp.next;
		}
	}
}