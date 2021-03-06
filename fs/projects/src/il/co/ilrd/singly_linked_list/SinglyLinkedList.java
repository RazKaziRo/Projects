package il.co.ilrd.singly_linked_list;


public class SinglyLinkedList {
	
	private Node headNode;
	
	public SinglyLinkedList(){
		this.headNode = new Node(null, null);
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
	
	public Object popFront(){
				
		Object data = null;
		
		if(!isEmpty()) {
			
			data = headNode.getData();
			headNode = headNode.nextNode;
		}
		
		return data;
	
	}
	
	public void pushFront(Object data) {
		
		Node newNode = new Node(data, headNode);
		headNode = newNode;
	}
	
	public boolean isEmpty() {
		
		return (headNode.nextNode == null);
	}
	
	public ListIterator find(Object data) {
		
		ListIterator itrRunner = new ListIteratorIMP();
		ListIterator itrHolder = null;
		
		Object dataHolder = null;
		
		while(itrRunner.hasNext()) {
			
			itrHolder = itrRunner;
			dataHolder = itrRunner.next();
			
			if(dataHolder != null && dataHolder.equals(data)) {
					
					return itrHolder;
				}
			}

		return null;
	};

	
	public ListIterator begin() {
		
		ListIterator itr = new ListIteratorIMP();
		
		return itr;
		
	}
	
	private class Node{
		
		private Object data;
		private Node nextNode;
		
		Node(Object data, Node nextNode){
			
			this.data = data;
			this.nextNode = nextNode;
		}

		public Object getData() {
			return data;
		}

		public Node getNextNode() {
			return nextNode;
		}
		
	}
	
	private class ListIteratorIMP implements ListIterator {

		private Node current;
		private Object dataHolder = null;
		
		ListIteratorIMP(){
			
			current = headNode;
		}
		
		@Override
		public boolean hasNext() {
			
			return (current.getNextNode() != null);	
			
		}

		@Override
		public Object next() {
						
			if(hasNext()) {
				
				dataHolder =  current.getData();
				current = current.getNextNode();
			}
			
			return dataHolder;
		}
	}

}
