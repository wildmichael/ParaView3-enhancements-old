
#include "vtkDataArrayMetaData.h"
#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkDataArrayMetaData);
vtkCxxRevisionMacro(vtkDataArrayMetaData, "$Revision: 1.1 $");

void vtkDataArrayMetaData::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
