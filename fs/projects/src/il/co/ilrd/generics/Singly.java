package il.co.ilrd.generics;

import java.util.ConcurrentModificationException;
import java.util.Iterator;


public class Singly<T> implements Iterable<T> {
	
	private Node<T> headNode;
	private volatile int modCount;
	
	public Singly() {
		
		headNode = new Node<T>(null, null); 
		modCount = 0;
	}
	
	public T popFront(){
		
		T data = null;
		
		if(!isEmpty()) {
			
			data = headNode.getData();
			headNode = headNode.nextNode;
			++modCount;
			return data;
		}
		
		throw new NullPointerException();
	}
	
	public void pushFront(T data) {
		
		Node<T> newNode = new Node<T>(data, headNode);
		headNode = newNode;
		++modCount;
	}
	
	public boolean isEmpty() {
		
		return (headNode.nextNode == null);
	}
	
	public int size() {
		
		int counter = 0;
		Node<T> nodeHolder = null;
		
		if(!isEmpty()) {
			
			nodeHolder = headNode.getNextNode();
			
			while(nodeHolder != null) {
				++counter;
				nodeHolder = nodeHolder.nextNode; 
			}
		}
		
		return counter;
	}
	
	private Node<T> getHeadNode() {
		return headNode;
	}

	
	private int getModCount() {
		return modCount;
	}


	private static class Node<T>{
		
		private Node<T> nextNode;
		private T data;

		private Node(T data, Node<T> nextNode){
			
			setData(data); 
			setNextNode(nextNode);
		}

		public Node<T> getNextNode() {
			return nextNode;
		}

		private void setNextNode(Node<T> nextNode) {
			this.nextNode = nextNode;
		}

		private T getData() {
			return data;
		}

		private void setData(T data) {
			this.data = data;
		}
		
	}
	
private static class SinglyIteratorIMP<T> implements Iterator <T>{
	
	private Node<T> currentNode;
	private Singly<T> list;
	private volatile int expectedModCount;

	private SinglyIteratorIMP(Singly<T> list) {
		
		this.list = list;
		currentNode = list.getHeadNode();
		expectedModCount = list.getModCount();
	}

	
	@Override
	public boolean hasNext() {
		
		if(list.getModCount() != expectedModCount) {
			
			throw new ConcurrentModificationException("ConcurrentModificationException");
		}
		
		return (currentNode.getNextNode() != null);
	}

	@Override
	public T next() {
		
		T dataHolder = null;
		
		if(hasNext() && list.getModCount() == expectedModCount) {
			
			dataHolder = currentNode.getData();
			currentNode = currentNode.getNextNode();
		}

		return dataHolder;
	}

}

@Override
public Iterator<T> iterator() {

	return new SinglyIteratorIMP<T>(this);
}

public Iterator<T> find(T data) {
	
	Iterator<T> runner = iterator();
	
	for (T element : this) {
		
		if (element.equals(data)) {
			return runner;
		}
		
		runner.next();
	}
	
	return null;
}

public static <E> Singly<E> merge(Singly<E> listA, Singly<E> listB){
		
	Singly<E> mergeSingly = new Singly<E>();
	for(E element : newReverse(listA)) {
		mergeSingly.pushFront(element);
	}
	
	for(E element : newReverse(listB)) {
		mergeSingly.pushFront(element);
	}
	
	return mergeSingly;
}

public static <E>Singly<E> newReverse(Singly<E> list){
	
	Singly<E> reverseSll = new Singly<E>();
	
	for(E element : list) {
		reverseSll.pushFront(element);
	}
	
	return reverseSll;
}

public static <E> void printSingly(Singly<E> list){
	
	for(E element : list) {
		System.out.println(element.toString());
	}
}

}
