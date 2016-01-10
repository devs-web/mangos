#ifndef CUSTOMVENDOR_H
#define CUSTOMVENDOR_H

class VendorEntry
{
    public:
	      int guid, entry, vendor_entry, group, daug_guid, icon;
	      std::string desc;
	      VendorEntry(int guid, int entry, int vendor_entry, int group, int daug_guid, int icon, std::string desc);
};

typedef std::list<VendorEntry *> VendorEntryList;

class CustomVendor
{
    public:
        VendorEntryList vendorEntryList;
        int LoadVendors(void);
        VendorEntryList* GetItemsForEntry(int, int);
};

extern CustomVendor CustomVendorMgr;

class VendorsId
{
    public:
        int entry;
        VendorsId(int entry);
};

typedef std::list<VendorsId *> VendorsIdList;


class CustomVendor2
{        
    public:
        VendorsIdList vendorsIdList;
        int LoadVendorsId(void);
        bool GetItemsForEntry(int entry);
};

extern CustomVendor2 CustomVendorMgr2;

#endif
