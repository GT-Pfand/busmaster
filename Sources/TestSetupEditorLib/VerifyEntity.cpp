/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file      VerifyEntity.cpp
 * \brief     This File Contains CVerfiyEntity Class Definitions
 * \author    Venkatanarayana makam
 * \copyright Copyright (c) 2011, Robert Bosch Engineering and Business Solutions. All rights reserved.
 *
 * This File Contains CVerfiyEntity Class Definitions
 */


#include "TestSetupEditorLib_stdafx.h"
#include "VerifyEntity.h"
#include "Verify_MessageEntity.h"

/******************************************************************************
Function Name  :  CVerifyEntity
Input(s)       :
Output         :  -
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
CVerifyEntity::CVerifyEntity(void)
{
    m_eType = VERIFY;
	this->m_ouData = new CVerifyData();
}


/******************************************************************************
Function Name  :  ~CVerifyEntity
Input(s)       :
Output         :  -
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
CVerifyEntity::~CVerifyEntity(void)
{
    // m_ouData->m_odVerifySubEntityList.RemoveAll();
	m_ouData->m_odVerifySubEntityList.clear();
}

/******************************************************************************
Function Name  :  CVerifyEntity
Input(s)       :  CVerifyEntity& RefObj
Output         :  -
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
CVerifyEntity::CVerifyEntity(const CVerifyEntity& RefObj)
{
    m_ouData = RefObj.m_ouData;
}

/******************************************************************************
Function Name  :  operator=
Input(s)       :  CVerifyEntity& RefObj
Output         :  -
Functionality  :
Member of      :  CVerifyEntity&
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
CVerifyEntity& CVerifyEntity::operator= (CVerifyEntity& RefObj)
{

    m_ouData = RefObj.m_ouData;
    return *this;
}


/******************************************************************************
Function Name  :  AddSubEntry
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::AddSubEntry(CBaseEntityTA* pouSubEntryObj)
{
    //m_ouData->m_odVerifySubEntityList.AddTail((CVerifySubEntity*)(pouSubEntryObj));
	m_ouData->m_odVerifySubEntityList.push_back((CVerifySubEntity*)(pouSubEntryObj));
    return  S_OK;
}


/******************************************************************************
Function Name  :  DeleteSubEntry
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
Codetag        :  CS017
******************************************************************************/
HRESULT CVerifyEntity::DeleteSubEntry(CBaseEntityTA* pouSubEntryObj)
{
    if(pouSubEntryObj!= NULL)
    {
        int nCount = (int) m_ouData->m_odVerifySubEntityList.size();
        for (int i = 0; i < nCount; i++)
        {
			CVerifySubEntity* pEntity = m_ouData->m_odVerifySubEntityList[i];
			if (pEntity->GetID() == pouSubEntryObj->GetID()) {
				m_ouData->m_odVerifySubEntityList.erase(m_ouData->m_odVerifySubEntityList.begin() + i);
				return S_OK;
			}
		}

        /*INT nCount = (INT)m_ouData->m_odVerifySubEntityList.size();
        for(int i = 0; i < nCount; i++)
        {
            POSITION pos = m_ouData->m_odVerifySubEntityList.FindIndex(i);
            CVerifySubEntity& pEntity = m_ouData->m_odVerifySubEntityList.GetAt(pos);

            if(pEntity.GetID() == pouSubEntryObj->GetID())
            {
                m_ouData->m_odVerifySubEntityList.RemoveAt(pos);
                return S_OK;
            }
        }*/
    }
    return S_FALSE;
}

/******************************************************************************
Function Name  :  DeleteSubEntry
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::DeleteSubEntry(unsigned int index)
{
	if (index >= m_ouData->m_odVerifySubEntityList.size()) {
		return S_OK;	
	}
    m_ouData->m_odVerifySubEntityList.erase(m_ouData->m_odVerifySubEntityList.begin() + index);
    return S_OK;
}

/******************************************************************************
Function Name  :  GetSubEntityObj
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
const HRESULT CVerifyEntity::GetSubEntityObj(UINT unIndex, CBaseEntityTA**  pouSubEntity)
{
    if (unIndex < m_ouData->m_odVerifySubEntityList.size())
    {
        *pouSubEntity = (m_ouData->m_odVerifySubEntityList[unIndex]);
        return  S_OK;
    }
    return ERR_WRONG_INDEX;
}

/******************************************************************************
Function Name  :  GetSubEntryCount
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::GetSubEntryCount(UINT& unTotal)
{
    unTotal = (UINT)m_ouData->m_odVerifySubEntityList.size();
    return  S_OK;
}


/******************************************************************************
Function Name  :  RepositionSubEntity
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
Codetag        :  CS020
******************************************************************************/
HRESULT CVerifyEntity::RepositionSubEntity(CBaseEntityTA* pouRefSubEntity, CBaseEntityTA* pouCurrSubEntity)
{
    UINT unCount = (INT)m_ouData->m_odVerifySubEntityList.size();
    CVerifySubEntity *ouSendEntity = (CVerifySubEntity*)pouRefSubEntity;
    for(unsigned int i = 0; i < unCount; i++)
    {
        CVerifySubEntity *ouSendMsgEntity = m_ouData->m_odVerifySubEntityList[i];
        if(ouSendMsgEntity->GetID() == pouRefSubEntity->GetID())
        {
            m_ouData->m_odVerifySubEntityList.erase(m_ouData->m_odVerifySubEntityList.begin() + i);
            break;
        }
    }
    if(pouCurrSubEntity == NULL)        //Insert At First Index;
    {
		m_ouData->m_odVerifySubEntityList.insert(m_ouData->m_odVerifySubEntityList.begin() ,ouSendEntity);
    } 
	else 
	{
		unCount = (INT)m_ouData->m_odVerifySubEntityList.size();
        for(unsigned int i = 0; i < unCount; i++)
        {
            CVerifySubEntity *ouSendMsgEntity = m_ouData->m_odVerifySubEntityList[i];
            if(ouSendMsgEntity->GetID() == pouCurrSubEntity->GetID())
            {
				// + 1 to insert after the element
                m_ouData->m_odVerifySubEntityList.insert(m_ouData->m_odVerifySubEntityList.begin() + i + 1, ouSendEntity);
                break;
            }
        }
    }

	return S_OK;
}

HRESULT CVerifyEntity::GetData(MSXML2::IXMLDOMNodePtr& pIDomNode)
{
	CVerifyData *verifyData = new CVerifyData();
    return this->GetCommonVerifyData(pIDomNode, verifyData);
}

/******************************************************************************
Function Name  :  GetData
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::GetCommonVerifyData(MSXML2::IXMLDOMNodePtr& pIDomNode, CVerifyData *verifyData)
{
	m_ouData = verifyData;
    _bstr_t bstrNodeName = def_STR_VERIFYMSG_NODE;
    CComVariant NodeValue;
    MSXML2::IXMLDOMNamedNodeMapPtr pDOMVerifyAtrributes;
    MSXML2::IXMLDOMNodePtr pIDOMChildNode;

    pDOMVerifyAtrributes = pIDomNode->Getattributes();
    //bstrNodeName = L"failure";
    bstrNodeName.Assign(SysAllocString(CT2W("failure")));
    pIDOMChildNode = pDOMVerifyAtrributes->getNamedItem(bstrNodeName);
    pIDOMChildNode->get_nodeTypedValue(&NodeValue);
    CString strTemp;
    strTemp = strCopyBSTRToCString(NodeValue);

	//m_ouData = new CVerifyData();
    if(strTemp == "SUCCESS")
    {
        m_ouData->m_eAttributeError = SUCCESS;
    }
    else if(strTemp == "WARNING")
    {
        m_ouData->m_eAttributeError = WARNING;
    }
    else if(strTemp == "ERRORS")
    {
        m_ouData->m_eAttributeError = ERRORS;
    }
    else
    {
        m_ouData->m_eAttributeError = FATAL;
    }
    MSXML2::IXMLDOMNodeListPtr pIDOMSendList;

    LONG lCount;
    //bstrNodeName = def_STR_VERIFYMSG_NODE;
    bstrNodeName.Assign(SysAllocString(CT2W(def_STR_VERIFYMSG_NODE)));
    pIDOMSendList = pIDomNode->selectNodes(bstrNodeName);
    pIDOMSendList->get_length(&lCount);

    for(int i = 0; i < lCount; i++)
    {
        CVerifySubEntity *odVerifySubEntity;
        MSXML2::IXMLDOMNodePtr pIXMLDOMVerifyMsgEntity;
        pIXMLDOMVerifyMsgEntity = pIDOMSendList->Getitem(i);
		//if(CVerifySubEntity::GetData(&odVerifySubEntity, pIXMLDOMVerifyMsgEntity) == S_OK)
		if(this->GetSubEntityData(&odVerifySubEntity, pIXMLDOMVerifyMsgEntity) == S_OK)
        {
            m_ouData->m_odVerifySubEntityList.push_back(odVerifySubEntity);
        }
    }
    return S_OK;
}


/******************************************************************************
Function Name  :  GetEntityData
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::GetEntityData(eTYPE_ENTITY eCurrEntityType, void* pvEntityData)
{
    if(eCurrEntityType == VERIFY && pvEntityData != NULL)
    {
        //pvEntityData = (void *) m_ouData;
		*((CVerifyData **)pvEntityData) = (CVerifyData *) m_ouData;
    }
    return  S_OK;
}
/******************************************************************************
Function Name  :  GetEntityType
Input(s)       :
Output         :  eTYPE_ENTITY
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
eTYPE_ENTITY CVerifyEntity::GetEntityType(void)
{
    return m_eType;
}

/******************************************************************************
Function Name  :  SetData
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
******************************************************************************/
HRESULT CVerifyEntity::SetData(MSXML2::IXMLDOMElementPtr& pIDomTestCaseNode)
{
    CString omstrTemp;
    MSXML2::IXMLDOMDocumentPtr pIDOMDoc;
    pIDOMDoc.CreateInstance(L"Msxml2.DOMDocument");


    int lCount = m_ouData->m_odVerifySubEntityList.size();
    MSXML2::IXMLDOMElementPtr pIDomSendNode =  pIDOMDoc->createElement(_bstr_t(def_STR_VERIFY_NODE));
    MSXML2::IXMLDOMAttributePtr pIDomTSAtrrib = pIDOMDoc->createAttribute(def_STR_ATTRIB_FAIL);
    if(pIDomTSAtrrib!= NULL)
    {
        switch(m_ouData->m_eAttributeError)
        {
            case SUCCESS:
                omstrTemp = "SUCCESS";
                break;
            case WARNING:
                omstrTemp = "WARNING";
                break;
            case FATAL:
                omstrTemp = "FATAL";
                break;
            case ERRORS:
            default:
                omstrTemp = "ERRORS";
                break;
        }
        pIDomTSAtrrib->value = _bstr_t(omstrTemp);
        pIDomSendNode->setAttributeNode(pIDomTSAtrrib);
    }

    for(INT i=0; i<lCount; i++)
    {
		CVerifySubEntity *pVerifySubEntity = m_ouData->m_odVerifySubEntityList[i];
        pVerifySubEntity->SetData(pIDomSendNode);
    }
    pIDomTestCaseNode->appendChild(pIDomSendNode);
    return S_OK;
}

/******************************************************************************
Function Name  :  SetEntityData
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  06/04/2011
Modifications  :
Codetag        :  CS015
******************************************************************************/
HRESULT CVerifyEntity::SetEntityData(eTYPE_ENTITY eCurrEntityType, void* pvEntityData)
{
    if(eCurrEntityType == VERIFY && pvEntityData != NULL)
    {
        m_ouData = (CVerifyData*)pvEntityData;
    }
    return  S_OK;
}

/******************************************************************************
Function Name  :  ValidateEntity
Input(s)       :
Output         :  HRESULT
Functionality  :
Member of      :  CVerifyEntity
Friend of      :  -
Author(s)      :  Venkatanarayana Makam
Date Created   :  13/04/2011
Modifications  :
Code Tag       :  CS030
******************************************************************************/
HRESULT CVerifyEntity::ValidateEntity(CString& omStrResult)
{
    UINT unVerifyMessageCount;
    GetSubEntryCount(unVerifyMessageCount);
    if(unVerifyMessageCount <= 0)
    {
        omStrResult += ("Error: Has No Verify Messages\r\n");       //CS030
        return ERR_VALID_ERROR;
    }
    return ERR_VALID_SUCCESS;
}

HRESULT CVerifyEntity::GetSubEntityData(CVerifySubEntity **odVerifySubEntity,MSXML2::IXMLDOMNodePtr pIXMLDOMVerifyMsgEntity) {
	CVerify_MessageEntity *verifyMessageEntity = new CVerify_MessageEntity();
	verifyMessageEntity->GetData(pIXMLDOMVerifyMsgEntity);
	*odVerifySubEntity = verifyMessageEntity;
	return S_OK;
}

CVerifyData::CVerifyData(void)
{
    m_odVerifySubEntityList.clear();
    m_eAttributeError = ERRORS;
}

CVerifyData::~CVerifyData(void)
{
}

CVerifyData& CVerifyData::operator=(const CVerifyData& RefObj)
{
    m_odVerifySubEntityList.clear();
    m_eAttributeError = RefObj.m_eAttributeError;
    INT Count = (INT)RefObj.m_odVerifySubEntityList.size();
    for(int i=0; i<Count; i++)
    {
        CVerifySubEntity *subEntity = (CVerifySubEntity *) RefObj.m_odVerifySubEntityList[i];
        m_odVerifySubEntityList.push_back(subEntity);
    }
    return *this;
}

