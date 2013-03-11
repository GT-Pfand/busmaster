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
 * \file      VerifyResponse.h
 * \author    Venkatanarayana makam
 * \copyright Copyright (c) 2011, Robert Bosch Engineering and Business Solutions. All rights reserved.
 */

#pragma once

#include "VerifyEntity.h"
#include "Verify_MessageEntity.h"

typedef CMap<UINT, UINT, CVerify_MessageData, CVerify_MessageData&> CVerifyMessageResponseMap;

class CVerifyResponseData : public CVerifyData
{
public:
    USHORT m_ushDuration;
};

class CVerifyResponse : public CVerifyEntity
{
public:
    CVerifyMessageResponseMap m_ouVerifyMsgMap;
    USHORT m_ushDuration;
public:
    CVerifyResponse(void);
    CVerifyResponse& operator= (CVerifyResponse& RefObj);
    CVerifyResponse(const CVerifyResponse& RefObj);
    //HRESULT AddSubEntry(CBaseEntityTA* pouSubEntryObj);
    //HRESULT DeleteSubEntry(CBaseEntityTA* pouSubEntryObj);
    //HRESULT DeleteSubEntry(INT index);
    HRESULT GetData(MSXML2::IXMLDOMNodePtr& pIDomNode);
    virtual HRESULT GetEntityData(eTYPE_ENTITY eCurrEntityType, void *pvEntityData);
    eTYPE_ENTITY GetEntityType(void);
	HRESULT GetSubEntityData(CVerifySubEntity **odVerifySubEntity,MSXML2::IXMLDOMNodePtr pIXMLDOMVerifyMsgEntity);
    //const HRESULT GetSubEntityObj(UINT unIndex, CBaseEntityTA**  pouSubEntity);
    //HRESULT GetSubEntryCount(UINT& unTotal);
    //HRESULT RepositionSubEntity(CBaseEntityTA* pouRefSubEntity, CBaseEntityTA* pouCurrSubEntity);
    HRESULT SetData(MSXML2::IXMLDOMElementPtr& pIDomTestCaseNode);
    virtual HRESULT SetEntityData(eTYPE_ENTITY eCurrEntityType, void *pvEntityData);
    HRESULT GetMessageFromId(UINT& unId, CVerify_MessageData* ouData);
    HRESULT ValidateEntity(CString& omStrResult);
    virtual ~CVerifyResponse(void);
};
