#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const 
  {
    cout << swaps_.size() << endl;
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << endl;
    }
  }

  void ReadData() 
  {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int LeftChild(int i)
  {
    return 2*i+1;
  }

  int RightChild(int i)
  {
    return 2*i+2;
  }

  int Parent(int i)
  {
    if(i==0)
    {
      return 0;
    }
    else
    {
      return (i-1)/2;
    }
  }

  void SiftUp(int i)
  {
    int x=i;

    while(x>0 && data_[Parent(x)]>data_[x])
    {
      swaps_.push_back(make_pair(Parent(x),x));
      swap(data_[Parent(x)], data_[x]);
      x=Parent(x);
    }
  }

  void SiftDown(int i)
  {
    int size= data_.size()-1;
    int maxIndex=i;
    int left=LeftChild(i);
    int right=RightChild(i);

    if(left<=size && data_[left]<data_[maxIndex])
    {
      maxIndex=left;
    }

    if(right<=size && data_[right]<data_[maxIndex])
    {
      maxIndex=right;
    }

    if(i!=maxIndex)
    {
      swaps_.push_back(make_pair(i,maxIndex));
      swap(data_[i], data_[maxIndex]);
      SiftDown(maxIndex);
    }
  }

  void GenerateSwaps() 
  {
    swaps_.clear();
    int n= data_.size();
    int mid=n/2;
    for(int i=mid; i>=0; --i)
    {
        SiftDown(i);
    }
  
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) 
      {
        if (data_[i] > data_[j]) 
        {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
      */
  }
  

 public:
  void Solve() 
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int32_t main() 
{
  IOS;
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
