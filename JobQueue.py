class JobQueue:
    def read_data(self):
        self.num_workers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        assert m == len(self.jobs)

    def write_response(self):
        for i in range(len(self.jobs)):
          print(self.assigned_workers[i], self.start_times[i]) 

    def assign_jobs(self):
        self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        min_heap = MinHeap(self.num_workers)
        for i in range(len(self.jobs)):
            self.assigned_workers[i] = min_heap._data[0][0]
            self.start_times[i] = min_heap._data[0][1]
            min_heap.ChangePriority(0, min_heap._data[0][1] + self.jobs[i])


    def solve(self):
        self.read_data()
        self.assign_jobs()
        self.write_response()
class MinHeap:
    def __init__(self, num_workers):
        # each worker contains (rank(index), next_free_time)
        self._data = []
        self.n = num_workers
        for i in range(num_workers):
            self._data.append((i, 0))

    def ChangePriority(self, index, priority):
        old_p = self._data[index][1]
        self._data[index] = (self._data[index][0], priority)
        if priority < old_p:
            self.SiftUp(index)
        else:
            self.SiftDown(index)

        self.SiftDown(index)
    def RepairHeap(self):
        for i in range(int(self.n / 2), -1, -1):
            self.SiftDown(i)

    def Parent(self, i):
        return self._data[int((i-1)/2)]

    def LeftChild(self, i):
        return 2 * i + 1

    def RightChild(self, i):
        return 2 * i + 2

    def CompareWorker(self, worker1, worker2):
        if worker1[1] != worker2[1]:
            return worker1[1] < worker2[1]
        else:
            return worker1[0] < worker2[0]

    def SiftUp(self, i):
        while i > 0 and self.CompareWorker(self._data[i], self._data[self.Parent(i)]):
            self._data[i], self._data[self.Parent(i)] = self._data[self.Parent(i)], self._data[i]
            i = self.Parent(i)
    def SiftDown(self, i):
        minIndex = i
        left = self.LeftChild(i)
        if left < self.n and self.CompareWorker(self._data[left], self._data[minIndex]):
            minIndex = left

        right = self.RightChild(i)
        if right < self.n and self.CompareWorker(self._data[right], self._data[minIndex]):
            minIndex = right
        if i != minIndex:
            self._data[i], self._data[minIndex] = self._data[minIndex], self._data[i]
            self.SiftDown(minIndex)

if __name__ == '__main__':
    job_queue = JobQueue()
    job_queue.solve()
