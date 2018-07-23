import java.util.Arrays;


public class getLeastNumbers {
public static void main(String[] args) {
getLeastNumbers test = new getLeastNumbers();
test.getLeastNumbers1(new int[]{4,5,1,6,2,7,3,8}, 4);
test.getLeastNumbers2(new int[]{4,5,1,6,2,7,3,8}, 4);
}
//思路1：基于快排的
void getLeastNumbers1(int[] array,int k){
if(array == null || k <= 0 || k > array.length){
return ;
}
int left = 0;
int right = array.length - 1;
int keyIndex = partirion(array, left, right);
while(keyIndex != k-1){
if(keyIndex > k-1){
right = keyIndex-1;
keyIndex = partirion(array, left, right);
}else{
left = keyIndex+1;
keyIndex = partirion(array, left, right);
}
}
for(int i = 0;i<=keyIndex;i++){
System.out.println(array[i]);
}
}
//一轮快排
Integer partirion(int[] array,int left,int right){
if(array == null){
return null;
}
int i = left;
int j = right;
int key = array[left];
while(i < j){
while(i < j && array[j] >= key){
j--;
}
array[i] = array[j];
while(i < j && array[i] <= key){
i++;
}
array[j] = array[i];
}
array[i] = key;
return i;
}
//思路2：借用一个保存有k个数字的大根堆
void getLeastNumbers2(int[] array,int k){
if(array==null || k<=0 || k>array.length){
return ;
}
//根据输入数组前k个数建立大根堆，从k+1个数开始与根节点比较，大于根节点则舍去，反之取代根节点并重排大根堆
int[] kArray = Arrays.copyOfRange(array, 0, k);
buildMaxHeapify(kArray);//建立大根堆
for(int i=k;i<array.length;i++){
if(array[i] < kArray[0]){//kArray[0]是堆顶
kArray[0] = array[i];
maxHeapify(kArray, k, 0);//替换堆顶后，执行堆排序以调整堆，保证堆顶数最大
}
}
for(int i:kArray){
System.out.println(i);
}
}
//建堆
void buildMaxHeapify(int[] array){
for(int i = (array.length-2) >> 1; i >= 0; i--){//这里i是最后一个非叶结点的数组下标
maxHeapify(array, array.length, i);//调整堆
}
}
//调整堆，递归法，参数heapSize为要调整的堆的大小，参数parent为当前堆顶的数组下标
void maxHeapify(int[] array,int heapSize,int parent)
{
int left = 2*parent+1;//左孩子下标
int right = left+1;//右孩子下标
int largest = parent;//最大值下标
if(left < heapSize && array[left] > array[parent]){
largest=left;
}
if(right < heapSize && array[right] > array[largest]){
largest=right;
}
//交换之后子结点可能就不满足堆的特性了，要继续调整
if(largest != parent){
int temp = array[parent];
array[parent] = array[largest];
array[largest] = temp;
maxHeapify(array, heapSize, largest);
}
}
//调整堆，循环法，参数heapSize为要调整的堆的大小，参数parent为当前堆顶的数组下标
//void maxHeapify(int[] array, int heapSize, int parent) {
//    int temp = array[parent]; // temp保存当前父节点
//    int child = 2 * parent + 1; // 先获得左孩子
//    while (child < heapSize) {
//        // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
//        if (child + 1 < heapSize && array[child] < array[child + 1]) {
//            child++;
//        }
//        // 如果父结点的值已经大于孩子结点的值，则直接结束
//        if (temp >= array[child]){
//        break;
//        }
//        // 把孩子结点的值赋给父结点
//        array[parent] = array[child];
//        // 选取孩子结点的左孩子结点,继续向下筛选
//        parent = child;
//        child = 2 * child + 1;
//    }
//    // 把原先父结点的值赋给现在的结点
//    array[parent] = temp;
//}
//堆排序，执行之前要先建堆！
void heapSort(int[] array){
for(int i = array.length-1;i>0;i--){
int temp = array[0];
array[0] = array[i];
array[i] = temp;
maxHeapify(array, i, 0);
}
}
}
