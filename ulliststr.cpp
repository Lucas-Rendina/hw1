#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"



#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
//As seen in the video, if this is the first element being
//pushed, create an item for it and add it to the front of 
//the item's array
  if(head_==NULL){
    Item* temp = new Item();
    temp->val[temp->first] = val;
    temp->last++;
    tail_ = temp;
    head_ = tail_;
  }
//If it will fit in the tail array, add it and increment last
  else if(tail_->last<ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
//Otherwise, create a new item, add it to that item, and modify 
//the pointers so that this item becomes the new tail
  else{
    Item* temp = new Item();
    temp->val[temp->first] = val;
    temp->last++;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }
  size_++;
}


/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
  //End function if the list is empty
    if(tail_==NULL){
      return;
    }
  //If item deletion is not needed, simply decrement last 
    else if(tail_->last>1){
      tail_->last--;
    }
    else{
//If there is only one item, delete it and set the head and tail
//back to NULL 
      if(head_==tail_){
        Item* temp1 = head_;
        head_ = NULL;
        tail_= NULL;
        delete temp1;
      }
//Set tail to its previous item and delete the old tail
      else{
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = NULL;
        delete temp;
      }
      
    }
    size_--;
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
 void ULListStr::push_front(const std::string& val){
 //If this is the first item, create it and add the value to the
 //back of the string array, setting both the head and tail 
 //pointers to this item
  if(head_==NULL){
    Item* temp = new Item();
    temp->val[ARRSIZE-1] = val;
    temp->first = ARRSIZE-1;
    temp->last = ARRSIZE;
    tail_ = temp;
    head_ = tail_;
  }
//if there is space in the head value array, add val to it and
//decrement first
  else if(head_->first>0){
    head_->val[head_->first-1] = val;
    head_->first--;
  }
//Otherwise, create a new item and add the value to the end of
//this item's array.Then set the pointers of the old tail and 
//the new item accordingly, assigning tail to this new item.
  else{
    Item* temp = new Item();
    temp->val[ARRSIZE-1] = val;
    temp->first = ARRSIZE-1;
    temp->last=ARRSIZE;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
  }
  size_++;

  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(head_==NULL){
      return;
    }
//If there is at least one string in head's value array,
//incrementing first effectively erases this value
    else if(head_->last - head_->first > 1){
      head_->first++;
    }
    else{
//If there is only one item(reaching this point also means there
//is no more than one value in the head->val), delete this item
//and set both head and tail to NULL 
      if(head_==tail_){
        Item* temp = tail_;
        tail_ = NULL;
        head_=NULL;
        delete temp;
      }
  //otherwise just set head to the next item and delete the old head
      else{
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        delete temp;
      }
    }
    size_--;
  }
  
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
    return tail_->val[tail_->last-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    return head_->val[head_->first];
  }


  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    Item* temp = head_;
//Loop to iterate through the items and decrement loc accordingly
//until the temp is NULL(loc is out of bounds) or the location
//is found.
    while(!(temp==NULL) && loc>=(temp->last-temp->first)){
      loc-=(temp->last-temp->first);
      
      temp = temp->next;
    }
//If the loop was broken and loc is still invalid, return NULL.
    if(temp==NULL || loc+temp->first >= temp->last){
        return NULL;
    }
//Otherwise, return a pointer to the value at the location.
    std::string* finval = &(temp->val[loc+temp->first]);
    return finval;
  }

//given functions
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
