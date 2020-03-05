
public class SinglyLinkedList {
	
	private Node head;
	
	SinglyLinkedList(){
		this.head = new Node(null, null);
	}
	
	public int size() {
		
		int counter = 0;
		Node nodeHolder = this.head;
		
		while(nodeHolder.getData() != null) {
			++counter;
			nodeHolder = nodeHolder.getNextNode();
		}
		
		return counter;
	}
	
	public boolean isEmpty() {
		
		return (this.head.nextNode == null);
	}
	
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
		
		ListIteratorIMP(){
			
			this.nodeHolder = head;
		}
		
		@Override
		public boolean hasNext() {
			
			return nodeHolder.getNextNode() != null;
		}

		@Override
		public Object next() {
			
			Object dataHolder = null;
			
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
		
		System.out.println(itr.hasNext());
		

	}

}
