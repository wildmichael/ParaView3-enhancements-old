/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkCTHFragmentProcessRing.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkCTHFragmentProcessRing
// .SECTION Description
// Data structure used to distribute work amongst available
// processes. The buffer can be intialized from a process
// priority queue such that only those processes with loading
// less than a specified tolerance are included.

#ifndef __vtkCTHFragmentProcessRing_h
#define __vtkCTHFragmentProcessRing_h

#include "vtkstd/vector"
#include "vtkCTHFragmentProcessPriorityQueue.h"

class vtkCTHFragmentProcessRing
{
  public:
    // Description:
    vtkCTHFragmentProcessRing()
    {
      this->Clear();
    }
    // Description:
    ~vtkCTHFragmentProcessRing()
    {
      this->Clear();
    }
    // Description:
    // Return the object to an empty state.
    void Clear()
    {
      this->NextElement=0;
      this->BufferSize=0;
      this->Buffer.clear();
    }
    // Description:
    // Size buffer and point to first element.
    void Initialize(int nProcs)
    {
      this->NextElement=0;
      this->BufferSize=nProcs;
      this->Buffer.resize(nProcs);
      for (int procId=0; procId<nProcs; ++procId)
        {
        this->Buffer[procId]=procId;
        }
    }
    // Description:
    // Build from a process loading priority queue.
    void Initialize(
        vtkCTHFragmentProcessPriorityQueue &Q,
        vtkIdType upperLoadingBound);
    // Description:
    // Get the next process id from the ring.
    int GetNextId()
    {
      int id=this->Buffer[this->NextElement];
      ++this->NextElement;
      if (this->NextElement==this->BufferSize)
        {
        this->NextElement=0;
        }
      return id;
    }
    // Description:
    // Print the state of the ring.
    void Print();

  private:
    int NextElement;
    int BufferSize;
    vtkstd::vector<int> Buffer;
};
#endif