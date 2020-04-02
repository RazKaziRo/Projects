package il.co.ilrd.generics;

import java.util.Iterator;


public class Singly<T> implements Iterable<T> {
	
	private Node headNode = new Node(null, null);
	
	public T popFront(){
		
		T data = null;
		
		if(!isEmpty()) {
			
			data = headNode.getData();
			headNode = headNode.nextNode;
		}
		
		return data;
	
	}
	
	public void pushFront(T data) {
		
		Node newNode = new Node(data, headNode);
		headNode = newNode;
	}
	
	public boolean isEmpty() {
		
		return (headNode.nextNode == null);
	}
	
	public int size() {
		
		int counter = 0;
		Node nodeHolder = null;
		
		if(!isEmpty()) {
			
			nodeHolder = headNode.getNextNode();
			
			while(nodeHolder != null) {
				++counter;
				nodeHolder = nodeHolder.nextNode; 
			}
		}
		
		return counter;
	}
	
	private class Node{
		
		private Node nextNode;
		private T data;

		public Node(T data, Node nextNode){
			
			setData(data);
			setNextNode(nextNode);
		}

		public Node getNextNode() {
			return nextNode;
		}

		private void setNextNode(Node nextNode) {
			this.nextNode = nextNode;
		}

		private T getData() {
			return data;
		}

		private void setData(T data) {
			this.data = data;
		}
		
	}
	
private class SinglyIteratorIMP implements Iterator<T>{
	
	private Node currentNode;

	public SinglyIteratorIMP() {
		
		currentNode = headNode;
	}

	
	@Override
	public boolean hasNext() {
		return (currentNode.getNextNode() != null);
	}

	@Override
	public T next() {
		
		T dataHolder = null;
		
		if(hasNext()) {
			
			dataHolder = currentNode.getData();
			currentNode = currentNode.getNextNode();
		}

		return dataHolder;
	}

}

@Override
public Iterator<T> iterator() { //FAIL SAFE
	
	return begin();
}

public Iterator<T> find(T data){
	
	Iterator<T> itrRunner = new SinglyIteratorIMP();
	Iterator<T> itrHolder = null;
	
	T dataHolder = null;
	
	while(itrRunner.hasNext()) {
		
		itrHolder = itrRunner;
		dataHolder = itrRunner.next();
		
		if(dataHolder.equals(data)) {
			
			return itrHolder;
		}
	}

	return null;
}

public Iterator<T> begin(){
	
	Iterator<T> itr = new SinglyIteratorIMP();
	
	return itr;
}

public static <E> Singly<E> merge(Singly<E> listA, Singly<E> listB){
		
return null;		
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
