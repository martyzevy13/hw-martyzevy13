#include "company.hpp"
using namespace std;
#include<iostream>

// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n)
{
  numCompanies = n;
  companies = new Company* [numCompanies];
  for (int i = 0; i < numCompanies; ++i)
      companies[i] = new Company ();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{
  // De-allocate all of the companies initially created in the CompanyTracker constructor
  for (int i = 0; i < numCompanies; i++){
    if (companies[i]) delete companies[i];
  }
  delete [] companies;

  //Delete companies I created during calls to "merge"
  for (unsigned int i = 0; i < mergers.size(); i++) if (mergers[i]) delete mergers[i];
}

void CompanyTracker::merge(int i, int j)
{
  //If one of the companies is out of range or they are the same company, return 
  if (i == j || i < 0 || j < 0 || i >= numCompanies || j >= numCompanies) return;
  if (inSameCompany(i, j)) return;

  //Find the largest companies i and j are a part of
  Company* iParent = largestParent(i);
  Company* jParent = largestParent(j);

  //Create a new parent company
  Company* newParent = new Company(iParent, jParent);
  iParent->parent = newParent;
  jParent->parent = newParent;
  mergers.push_back(newParent); //Store the new company so that I can delete it later
}

void CompanyTracker::split(int i)
{
  if (i < 0 || i >= numCompanies) return;  // Make sure i is in range
  Company* largest = largestParent(i);
  if (!largest->merge1 && !largest->merge2) return;   //Check if company i is a single person company
  
  //Get rid of the parent company
  if (largest->merge1) largest->merge1->parent = nullptr;
  if (largest->merge2) largest->merge2->parent = nullptr;
  largest = nullptr;
  delete largest;
}

bool CompanyTracker::inSameCompany(int i, int j)
{
  //Make sure company i and j are valid and not the same company
  if (i == j) return true;
  if (i < 0 || j < 0 || i >= numCompanies || j >= numCompanies) return false;

  //Get the largest parent i and j are a part of
  Company* iParent = largestParent(i);
  Company* jParent = largestParent(j);
  return sameCompany(iParent, jParent); //Call helper function
}

bool CompanyTracker::sameCompany(Company* i, Company* j)
{
  if (!i || !j) return false;
  if (i == j) return true;
  //Check to see if i or j or either of their parents are the same company
  return sameCompany(i->merge1, j) || sameCompany(i->merge2, j) || sameCompany(i, j->merge1) || sameCompany(i, j->merge2);
}

Company* CompanyTracker::largestParent(int i)
{
  Company* temp = companies[i];
  while (temp->parent) temp = temp->parent; //Get the company that doesn't have a parent. The largest company. 
  return temp;
}


