#include "CustomVendor.h"
#include <stdio.h>
#include <string>
#include <list>

CustomVendor CustomVendorMgr;
CustomVendor2 CustomVendorMgr2;

int CustomVendor::LoadVendors(void)
{
	vendorEntryList.clear();
	int i = 0;
	QueryResult* result = WorldDatabase.PQuery("SELECT `guid`, `entry`, `vendor_entry`, `group`, `daug_guid`, `icon`, `desc` FROM _customvendors ORDER BY `sort` ASC");

	if (result)
	{
		do
		{
			Field *fields    = result->Fetch();
			int guid         = fields[0].GetInt32();
			int entry        = fields[1].GetInt32();
			int vendor_entry = fields[2].GetInt32();
			int group        = fields[3].GetInt32();
			int daug_guid    = fields[4].GetInt32();
			int icon         = fields[5].GetInt32();
			std::string desc  = fields[6].GetString();

			vendorEntryList.push_back(new VendorEntry(guid, entry, vendor_entry, group, daug_guid, icon, desc));
			i++;
		}
    	while (result->NextRow());
	}

    CustomVendor2 *CstVendor = new CustomVendor2;
    CstVendor->LoadVendorsId();
    return i;
}

VendorEntry::VendorEntry(int guid, int entry, int vendor_entry, int group, int daug_guid, int icon, std::string desc)
{
    this->guid         = guid;
    this->entry        = entry;
    this->vendor_entry = vendor_entry;
    this->group        = group;
    this->daug_guid    = daug_guid;
    this->icon         = icon;
    this->desc         = desc;
}

VendorEntryList* CustomVendor::GetItemsForEntry(int entry, int id)
{
    VendorEntryList *result = new VendorEntryList();

    for (VendorEntryList::iterator i = vendorEntryList.begin(); i != vendorEntryList.end(); ++i)
    {
        VendorEntry *vendorEntry = *i;
		
        if (vendorEntry->entry == entry)
        {
            result->push_back(vendorEntry);
        }
    }
    return result;
}

bool CustomVendor2::GetItemsForEntry(int entry)
{
    for (VendorsIdList::iterator i = vendorsIdList.begin(); i != vendorsIdList.end(); ++i)
    {
        VendorsId *data = *i;
        if (data->entry == entry)
            return true;
    }
    return false;
}

int CustomVendor2::LoadVendorsId(void)
{
    vendorsIdList.clear();
    int i = 0;
    QueryResult* result2 = WorldDatabase.PQuery("select entry from _customvendors group by (entry)");
    if (result2)
    {
        do
        {
            Field *fields = result2->Fetch();
            int entry    = fields[0].GetInt32();

            vendorsIdList.push_back(new VendorsId(entry));
            i++;
        }
        while (result2->NextRow());
    }
    return i;
}

VendorsId::VendorsId(int entry)
{
    this->entry        = entry;
}
