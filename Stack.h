#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

template <class T>
//LinkedList class를 상속받음
class Stack : public LinkedList<T>{
	public:
		// Delete 함수 재정의
		virtual bool Delete(T& element) {
			//first가 0이면 false반환
			if (this->first == 0)
				return false;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			else {
				// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제함

				
				// current가 가리키는 노드를 삭제 후 다음 노드를 first로 지정, 스택에서 데이터를 pop하는 역할 수행
				Node<T>* current = this->first;
				this->first = current->link;
				
				
				// 이후 current의 데이터를 element에 저장하고 메모리를 해제한 뒤 current_size를 감소
				element = current->data;
				delete current;
				this->current_size--; 

				// 성공적으로 삭제 후 true 리턴
				return true; 
			}
			return true;
		}
			
};
