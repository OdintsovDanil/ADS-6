// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
	T arr[5];
	int first;
	int last;

 public:
	TPQueue() {
		first = 0;
		last = 0;
	}
	void push(T elem) {
		if (last - first >= size) {
			cout << "Full!" << endl;
		} else {
			int iter = last++;
			for (iter; (--iter >= first) && (arr[iter % size].prior < elem.prior);) {
				arr[(iter + 1) % size] = arr[iter % size];
			}
			arr[(iter + 1) % size] = elem;
		}
	}
	T pop() {
		return arr[(first++) % size];
	}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
