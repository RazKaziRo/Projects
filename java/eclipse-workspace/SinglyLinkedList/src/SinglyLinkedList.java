
public class SinglyLinkedList {
	
	private Node headNode;
	
	SinglyLinkedList(){
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
		
		Node nodeHolder = null;
		
		if(!isEmpty()) {
			
			nodeHolder = headNode;
			headNode = nodeHolder.nextNode;
		}
		
		return nodeHolder.getData();
	
	}
	
	public void pushFront(Object data) {
		
		//Node nodeHolder = headNode.nextNode;
		Node newNode = new Node(data, headNode);
		//headNode.nextNode = newNode;
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

		private Node nodeHolder;
		private Object dataHolder = null;
		
		ListIteratorIMP(){
			
			this.nodeHolder = headNode;
			this.dataHolder = headNode.data;
		}
		
		@Override
		public boolean hasNext() {
			
			return headNode.nextNode != null;
		}

		@Override
		public Object next() {
			
			if(hasNext()) {
				
				dataHolder = nodeHolder.getData();
				nodeHolder = nodeHolder.getNextNode();
			}
			
			return dataHolder;
		}
	}
	
	public static void main(String[] args) {
		
		SinglyLinkedList sll1 = new SinglyLinkedList();
		ListIterator itr = sll1.begin();
		
		System.out.println("SIZE 0: " + sll1.size());

		System.out.println("HAS NEXT FALSE: " + itr.hasNext());

		sll1.pushFront(10);
		
		System.out.println("HAS NEXT TRUE: " + itr.hasNext());

		System.out.println("SIZE 1: " + sll1.size());

		sll1.pushFront(20);
		sll1.pushFront(30);
		sll1.pushFront(40);
		sll1.pushFront(50);

		ListIterator itrFinder = sll1.find(50);
		System.out.println(itrFinder);
		
		System.out.println("SIZE 5: " + sll1.size());
		
		System.out.println("POP FRONT (50): " + sll1.popFront());
		System.out.println("POP FRONT (40): " + sll1.popFront());
		
		System.out.println("SIZE 3 AFTER 2 POP: " + sll1.size());
		System.out.println("HAS NEXT TRUE: " + itr.hasNext());
		
		System.out.println("POP FRONT (30): " + sll1.popFront());
		System.out.println("POP FRONT (20): " + sll1.popFront());
		System.out.println("POP FRONT (10): " + sll1.popFront());
		
		System.out.println("HAS NEXT FALSE: " + itr.hasNext());
		System.out.println("SIZE 0: " + sll1.size());

	}

}
