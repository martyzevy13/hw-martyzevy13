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
  // your implementation goes here
  //for (int i = 0; i < mergers.size(); i++) delete mergers[i];
  for (int i = 0; i < numCompanies; i++){
    if (companies[i]) delete companies[i];
  }
  delete [] companies;
  for (unsigned int i = 0; i < mergers.size(); i++) if (mergers[i]) delete mergers[i];
}

void CompanyTracker::merge(int i, int j)
{
  // your implementation goes here
  if (i == j || i < 0 || j < 0 || i >= numCompanies || j >= numCompanies) return;
  if (inSameCompany(i, j)) return;
  Company* iParent = largestParent(i);
  Company* jParent = largestParent(j);
  Company* newParent = new Company(iParent, jParent);
  iParent->parent = newParent;
  jParent->parent = newParent;
  mergers.push_back(newParent);
}

void CompanyTracker::split(int i)
{
  // your implementation goes here
  if (i < 0 || i >= numCompanies) return;
  Company* largest = largestParent(i);
  if (!largest->merge1 && !largest->merge2) return;
  if (largest->merge1) largest->merge1->parent = nullptr;
  if (largest->merge2) largest->merge2->parent = nullptr;
  largest = nullptr;
  delete largest;
}

bool CompanyTracker::inSameCompany(int i, int j)
{
  // your implementation goes here
  if (i == j) return true;
  if (i < 0 || j < 0 || i >= numCompanies || j >= numCompanies) return false;
  Company* iParent = largestParent(i);
  Company* jParent = largestParent(j);
  return sameCompany(iParent, jParent);
}

bool CompanyTracker::sameCompany(Company* i, Company* j)
{
  if (!i || !j) return false;
  if (i == j) return true;
  return sameCompany(i->merge1, j) || sameCompany(i->merge2, j) || sameCompany(i, j->merge1) || sameCompany(i, j->merge2);
}

Company* CompanyTracker::largestParent(int i)
{
  Company* temp = companies[i];
  while (temp->parent) temp = temp->parent;
  return temp;
}


