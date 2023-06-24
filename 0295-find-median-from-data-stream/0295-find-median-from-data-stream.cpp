class MedianFinder {
public:
  priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int> maxHeap;
    MedianFinder() {
        
    }
    // We want to mantain 2 heaps.
    // maxheap = left of the median 
    // minheap = right of the median
    void addNum(int num) {

        // Go to left or right
        if (maxHeap.empty() || maxHeap.top()>num) 
            maxHeap.push(num); 
        else 
            minHeap.push(num);


        // maintain both heaps sizes
        if (maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } 
    }
    
    double findMedian() {

        if (maxHeap.size() == minHeap.size()){
            if (maxHeap.empty()) 
                return 0;
            else 
                return (double) (maxHeap.top()+minHeap.top())/2.0;
        }
        else {
            if (maxHeap.size()>minHeap.size()) 
                return maxHeap.top();
            else 
                return minHeap.top();
        }
        
    }
};