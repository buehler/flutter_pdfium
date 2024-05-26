
#include "flutter_pdfium.h"

FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetMediaBox(FPDF_PAGE page,float left,float bottom,float right,float top){
return FPDFPage_SetMediaBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetCropBox(FPDF_PAGE page,float left,float bottom,float right,float top){
return FPDFPage_SetCropBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetBleedBox(FPDF_PAGE page,float left,float bottom,float right,float top){
return FPDFPage_SetBleedBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetTrimBox(FPDF_PAGE page,float left,float bottom,float right,float top){
return FPDFPage_SetTrimBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetArtBox(FPDF_PAGE page,float left,float bottom,float right,float top){
return FPDFPage_SetArtBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GetMediaBox(FPDF_PAGE page,float * left,float * bottom,float * right,float * top){
return FPDFPage_GetMediaBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GetCropBox(FPDF_PAGE page,float * left,float * bottom,float * right,float * top){
return FPDFPage_GetCropBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GetBleedBox(FPDF_PAGE page,float * left,float * bottom,float * right,float * top){
return FPDFPage_GetBleedBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GetTrimBox(FPDF_PAGE page,float * left,float * bottom,float * right,float * top){
return FPDFPage_GetTrimBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GetArtBox(FPDF_PAGE page,float * left,float * bottom,float * right,float * top){
return FPDFPage_GetArtBox(page,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_TransFormWithClip(FPDF_PAGE page,const FS_MATRIX * matrix,const FS_RECTF * clipRect){
return FPDFPage_TransFormWithClip(page,matrix,clipRect);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPageObj_TransformClipPath(FPDF_PAGEOBJECT page_object,double a,double b,double c,double d,double e,double f){
return FPDFPageObj_TransformClipPath(page_object,a,b,c,d,e,f);
}
FFI_PLUGIN_EXPORT FPDF_CLIPPATH PDFIUM_FPDFPageObj_GetClipPath(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_GetClipPath(page_object);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFClipPath_CountPaths(FPDF_CLIPPATH clip_path){
return FPDFClipPath_CountPaths(clip_path);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFClipPath_CountPathSegments(FPDF_CLIPPATH clip_path,int path_index){
return FPDFClipPath_CountPathSegments(clip_path,path_index);
}
FFI_PLUGIN_EXPORT FPDF_PATHSEGMENT PDFIUM_FPDFClipPath_GetPathSegment(FPDF_CLIPPATH clip_path,int path_index,int segment_index){
return FPDFClipPath_GetPathSegment(clip_path,path_index,segment_index);
}
FFI_PLUGIN_EXPORT FPDF_CLIPPATH PDFIUM_FPDF_CreateClipPath(float left,float bottom,float right,float top){
return FPDF_CreateClipPath(left,bottom,right,top);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_DestroyClipPath(FPDF_CLIPPATH clipPath){
return FPDF_DestroyClipPath(clipPath);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_InsertClipPath(FPDF_PAGE page,FPDF_CLIPPATH clipPath){
return FPDFPage_InsertClipPath(page,clipPath);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_IsSupportedSubtype(FPDF_ANNOTATION_SUBTYPE subtype){
return FPDFAnnot_IsSupportedSubtype(subtype);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION PDFIUM_FPDFPage_CreateAnnot(FPDF_PAGE page,FPDF_ANNOTATION_SUBTYPE subtype){
return FPDFPage_CreateAnnot(page,subtype);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_GetAnnotCount(FPDF_PAGE page){
return FPDFPage_GetAnnotCount(page);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION PDFIUM_FPDFPage_GetAnnot(FPDF_PAGE page,int index){
return FPDFPage_GetAnnot(page,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_GetAnnotIndex(FPDF_PAGE page,FPDF_ANNOTATION annot){
return FPDFPage_GetAnnotIndex(page,annot);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_CloseAnnot(FPDF_ANNOTATION annot){
return FPDFPage_CloseAnnot(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_RemoveAnnot(FPDF_PAGE page,int index){
return FPDFPage_RemoveAnnot(page,index);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION_SUBTYPE PDFIUM_FPDFAnnot_GetSubtype(FPDF_ANNOTATION annot){
return FPDFAnnot_GetSubtype(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_IsObjectSupportedSubtype(FPDF_ANNOTATION_SUBTYPE subtype){
return FPDFAnnot_IsObjectSupportedSubtype(subtype);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_UpdateObject(FPDF_ANNOTATION annot,FPDF_PAGEOBJECT obj){
return FPDFAnnot_UpdateObject(annot,obj);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_AddInkStroke(FPDF_ANNOTATION annot,const FS_POINTF * points,size_t point_count){
return FPDFAnnot_AddInkStroke(annot,points,point_count);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_RemoveInkList(FPDF_ANNOTATION annot){
return FPDFAnnot_RemoveInkList(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_AppendObject(FPDF_ANNOTATION annot,FPDF_PAGEOBJECT obj){
return FPDFAnnot_AppendObject(annot,obj);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetObjectCount(FPDF_ANNOTATION annot){
return FPDFAnnot_GetObjectCount(annot);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFAnnot_GetObject(FPDF_ANNOTATION annot,int index){
return FPDFAnnot_GetObject(annot,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_RemoveObject(FPDF_ANNOTATION annot,int index){
return FPDFAnnot_RemoveObject(annot,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetColor(FPDF_ANNOTATION annot,FPDFANNOT_COLORTYPE type,unsigned int R,unsigned int G,unsigned int B,unsigned int A){
return FPDFAnnot_SetColor(annot,type,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetColor(FPDF_ANNOTATION annot,FPDFANNOT_COLORTYPE type,unsigned int * R,unsigned int * G,unsigned int * B,unsigned int * A){
return FPDFAnnot_GetColor(annot,type,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_HasAttachmentPoints(FPDF_ANNOTATION annot){
return FPDFAnnot_HasAttachmentPoints(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetAttachmentPoints(FPDF_ANNOTATION annot,size_t quad_index,const FS_QUADPOINTSF * quad_points){
return FPDFAnnot_SetAttachmentPoints(annot,quad_index,quad_points);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_AppendAttachmentPoints(FPDF_ANNOTATION annot,const FS_QUADPOINTSF * quad_points){
return FPDFAnnot_AppendAttachmentPoints(annot,quad_points);
}
FFI_PLUGIN_EXPORT size_t PDFIUM_FPDFAnnot_CountAttachmentPoints(FPDF_ANNOTATION annot){
return FPDFAnnot_CountAttachmentPoints(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetAttachmentPoints(FPDF_ANNOTATION annot,size_t quad_index,FS_QUADPOINTSF * quad_points){
return FPDFAnnot_GetAttachmentPoints(annot,quad_index,quad_points);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetRect(FPDF_ANNOTATION annot,const FS_RECTF * rect){
return FPDFAnnot_SetRect(annot,rect);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetRect(FPDF_ANNOTATION annot,FS_RECTF * rect){
return FPDFAnnot_GetRect(annot,rect);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetVertices(FPDF_ANNOTATION annot,FS_POINTF * buffer,unsigned long length){
return FPDFAnnot_GetVertices(annot,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetInkListCount(FPDF_ANNOTATION annot){
return FPDFAnnot_GetInkListCount(annot);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetInkListPath(FPDF_ANNOTATION annot,unsigned long path_index,FS_POINTF * buffer,unsigned long length){
return FPDFAnnot_GetInkListPath(annot,path_index,buffer,length);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetLine(FPDF_ANNOTATION annot,FS_POINTF * start,FS_POINTF * end){
return FPDFAnnot_GetLine(annot,start,end);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetBorder(FPDF_ANNOTATION annot,float horizontal_radius,float vertical_radius,float border_width){
return FPDFAnnot_SetBorder(annot,horizontal_radius,vertical_radius,border_width);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetBorder(FPDF_ANNOTATION annot,float * horizontal_radius,float * vertical_radius,float * border_width){
return FPDFAnnot_GetBorder(annot,horizontal_radius,vertical_radius,border_width);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetFormAdditionalActionJavaScript(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,int event,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetFormAdditionalActionJavaScript(hHandle,annot,event,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_HasKey(FPDF_ANNOTATION annot,FPDF_BYTESTRING key){
return FPDFAnnot_HasKey(annot,key);
}
FFI_PLUGIN_EXPORT FPDF_OBJECT_TYPE PDFIUM_FPDFAnnot_GetValueType(FPDF_ANNOTATION annot,FPDF_BYTESTRING key){
return FPDFAnnot_GetValueType(annot,key);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetStringValue(FPDF_ANNOTATION annot,FPDF_BYTESTRING key,FPDF_WIDESTRING value){
return FPDFAnnot_SetStringValue(annot,key,value);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetStringValue(FPDF_ANNOTATION annot,FPDF_BYTESTRING key,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetStringValue(annot,key,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetNumberValue(FPDF_ANNOTATION annot,FPDF_BYTESTRING key,float * value){
return FPDFAnnot_GetNumberValue(annot,key,value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetAP(FPDF_ANNOTATION annot,FPDF_ANNOT_APPEARANCEMODE appearanceMode,FPDF_WIDESTRING value){
return FPDFAnnot_SetAP(annot,appearanceMode,value);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetAP(FPDF_ANNOTATION annot,FPDF_ANNOT_APPEARANCEMODE appearanceMode,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetAP(annot,appearanceMode,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION PDFIUM_FPDFAnnot_GetLinkedAnnot(FPDF_ANNOTATION annot,FPDF_BYTESTRING key){
return FPDFAnnot_GetLinkedAnnot(annot,key);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFlags(FPDF_ANNOTATION annot){
return FPDFAnnot_GetFlags(annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetFlags(FPDF_ANNOTATION annot,int flags){
return FPDFAnnot_SetFlags(annot,flags);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFormFieldFlags(FPDF_FORMHANDLE handle,FPDF_ANNOTATION annot){
return FPDFAnnot_GetFormFieldFlags(handle,annot);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION PDFIUM_FPDFAnnot_GetFormFieldAtPoint(FPDF_FORMHANDLE hHandle,FPDF_PAGE page,const FS_POINTF * point){
return FPDFAnnot_GetFormFieldAtPoint(hHandle,page,point);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetFormFieldName(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetFormFieldName(hHandle,annot,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetFormFieldAlternateName(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetFormFieldAlternateName(hHandle,annot,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFormFieldType(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot){
return FPDFAnnot_GetFormFieldType(hHandle,annot);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetFormFieldValue(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetFormFieldValue(hHandle,annot,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetOptionCount(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot){
return FPDFAnnot_GetOptionCount(hHandle,annot);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetOptionLabel(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,int index,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetOptionLabel(hHandle,annot,index,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_IsOptionSelected(FPDF_FORMHANDLE handle,FPDF_ANNOTATION annot,int index){
return FPDFAnnot_IsOptionSelected(handle,annot,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetFontSize(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,float * value){
return FPDFAnnot_GetFontSize(hHandle,annot,value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_IsChecked(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot){
return FPDFAnnot_IsChecked(hHandle,annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetFocusableSubtypes(FPDF_FORMHANDLE hHandle,const FPDF_ANNOTATION_SUBTYPE * subtypes,size_t count){
return FPDFAnnot_SetFocusableSubtypes(hHandle,subtypes,count);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFocusableSubtypesCount(FPDF_FORMHANDLE hHandle){
return FPDFAnnot_GetFocusableSubtypesCount(hHandle);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_GetFocusableSubtypes(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION_SUBTYPE * subtypes,size_t count){
return FPDFAnnot_GetFocusableSubtypes(hHandle,subtypes,count);
}
FFI_PLUGIN_EXPORT FPDF_LINK PDFIUM_FPDFAnnot_GetLink(FPDF_ANNOTATION annot){
return FPDFAnnot_GetLink(annot);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFormControlCount(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot){
return FPDFAnnot_GetFormControlCount(hHandle,annot);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAnnot_GetFormControlIndex(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot){
return FPDFAnnot_GetFormControlIndex(hHandle,annot);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAnnot_GetFormFieldExportValue(FPDF_FORMHANDLE hHandle,FPDF_ANNOTATION annot,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAnnot_GetFormFieldExportValue(hHandle,annot,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAnnot_SetURI(FPDF_ANNOTATION annot,const char * uri){
return FPDFAnnot_SetURI(annot,uri);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_Flatten(FPDF_PAGE page,int nFlag){
return FPDFPage_Flatten(page,nFlag);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetCharIndexFromTextIndex(FPDF_TEXTPAGE text_page,int nTextIndex){
return FPDFText_GetCharIndexFromTextIndex(text_page,nTextIndex);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetTextIndexFromCharIndex(FPDF_TEXTPAGE text_page,int nCharIndex){
return FPDFText_GetTextIndexFromCharIndex(text_page,nCharIndex);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_SaveAsCopy(FPDF_DOCUMENT document,FPDF_FILEWRITE * pFileWrite,FPDF_DWORD flags){
return FPDF_SaveAsCopy(document,pFileWrite,flags);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_SaveWithVersion(FPDF_DOCUMENT document,FPDF_FILEWRITE * pFileWrite,FPDF_DWORD flags,int fileVersion){
return FPDF_SaveWithVersion(document,pFileWrite,flags,fileVersion);
}
FFI_PLUGIN_EXPORT FPDF_BOOKMARK PDFIUM_FPDFBookmark_GetFirstChild(FPDF_DOCUMENT document,FPDF_BOOKMARK bookmark){
return FPDFBookmark_GetFirstChild(document,bookmark);
}
FFI_PLUGIN_EXPORT FPDF_BOOKMARK PDFIUM_FPDFBookmark_GetNextSibling(FPDF_DOCUMENT document,FPDF_BOOKMARK bookmark){
return FPDFBookmark_GetNextSibling(document,bookmark);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFBookmark_GetTitle(FPDF_BOOKMARK bookmark,void * buffer,unsigned long buflen){
return FPDFBookmark_GetTitle(bookmark,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFBookmark_GetCount(FPDF_BOOKMARK bookmark){
return FPDFBookmark_GetCount(bookmark);
}
FFI_PLUGIN_EXPORT FPDF_BOOKMARK PDFIUM_FPDFBookmark_Find(FPDF_DOCUMENT document,FPDF_WIDESTRING title){
return FPDFBookmark_Find(document,title);
}
FFI_PLUGIN_EXPORT FPDF_DEST PDFIUM_FPDFBookmark_GetDest(FPDF_DOCUMENT document,FPDF_BOOKMARK bookmark){
return FPDFBookmark_GetDest(document,bookmark);
}
FFI_PLUGIN_EXPORT FPDF_ACTION PDFIUM_FPDFBookmark_GetAction(FPDF_BOOKMARK bookmark){
return FPDFBookmark_GetAction(bookmark);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAction_GetType(FPDF_ACTION action){
return FPDFAction_GetType(action);
}
FFI_PLUGIN_EXPORT FPDF_DEST PDFIUM_FPDFAction_GetDest(FPDF_DOCUMENT document,FPDF_ACTION action){
return FPDFAction_GetDest(document,action);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAction_GetFilePath(FPDF_ACTION action,void * buffer,unsigned long buflen){
return FPDFAction_GetFilePath(action,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAction_GetURIPath(FPDF_DOCUMENT document,FPDF_ACTION action,void * buffer,unsigned long buflen){
return FPDFAction_GetURIPath(document,action,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFDest_GetDestPageIndex(FPDF_DOCUMENT document,FPDF_DEST dest){
return FPDFDest_GetDestPageIndex(document,dest);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFDest_GetView(FPDF_DEST dest,unsigned long * pNumParams,FS_FLOAT * pParams){
return FPDFDest_GetView(dest,pNumParams,pParams);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFDest_GetLocationInPage(FPDF_DEST dest,FPDF_BOOL * hasXVal,FPDF_BOOL * hasYVal,FPDF_BOOL * hasZoomVal,FS_FLOAT * x,FS_FLOAT * y,FS_FLOAT * zoom){
return FPDFDest_GetLocationInPage(dest,hasXVal,hasYVal,hasZoomVal,x,y,zoom);
}
FFI_PLUGIN_EXPORT FPDF_LINK PDFIUM_FPDFLink_GetLinkAtPoint(FPDF_PAGE page,double x,double y){
return FPDFLink_GetLinkAtPoint(page,x,y);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFLink_GetLinkZOrderAtPoint(FPDF_PAGE page,double x,double y){
return FPDFLink_GetLinkZOrderAtPoint(page,x,y);
}
FFI_PLUGIN_EXPORT FPDF_DEST PDFIUM_FPDFLink_GetDest(FPDF_DOCUMENT document,FPDF_LINK link){
return FPDFLink_GetDest(document,link);
}
FFI_PLUGIN_EXPORT FPDF_ACTION PDFIUM_FPDFLink_GetAction(FPDF_LINK link){
return FPDFLink_GetAction(link);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFLink_Enumerate(FPDF_PAGE page,int * start_pos,FPDF_LINK * link_annot){
return FPDFLink_Enumerate(page,start_pos,link_annot);
}
FFI_PLUGIN_EXPORT FPDF_ANNOTATION PDFIUM_FPDFLink_GetAnnot(FPDF_PAGE page,FPDF_LINK link_annot){
return FPDFLink_GetAnnot(page,link_annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFLink_GetAnnotRect(FPDF_LINK link_annot,FS_RECTF * rect){
return FPDFLink_GetAnnotRect(link_annot,rect);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFLink_CountQuadPoints(FPDF_LINK link_annot){
return FPDFLink_CountQuadPoints(link_annot);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFLink_GetQuadPoints(FPDF_LINK link_annot,int quad_index,FS_QUADPOINTSF * quad_points){
return FPDFLink_GetQuadPoints(link_annot,quad_index,quad_points);
}
FFI_PLUGIN_EXPORT FPDF_ACTION PDFIUM_FPDF_GetPageAAction(FPDF_PAGE page,int aa_type){
return FPDF_GetPageAAction(page,aa_type);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetFileIdentifier(FPDF_DOCUMENT document,FPDF_FILEIDTYPE id_type,void * buffer,unsigned long buflen){
return FPDF_GetFileIdentifier(document,id_type,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetMetaText(FPDF_DOCUMENT document,FPDF_BYTESTRING tag,void * buffer,unsigned long buflen){
return FPDF_GetMetaText(document,tag,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetPageLabel(FPDF_DOCUMENT document,int page_index,void * buffer,unsigned long buflen){
return FPDF_GetPageLabel(document,page_index,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_FORMHANDLE PDFIUM_FPDFDOC_InitFormFillEnvironment(FPDF_DOCUMENT document,FPDF_FORMFILLINFO * formInfo){
return FPDFDOC_InitFormFillEnvironment(document,formInfo);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFDOC_ExitFormFillEnvironment(FPDF_FORMHANDLE hHandle){
return FPDFDOC_ExitFormFillEnvironment(hHandle);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_HasFormFieldAtPoint(FPDF_FORMHANDLE hHandle,FPDF_PAGE page,double page_x,double page_y){
return FPDFPage_HasFormFieldAtPoint(hHandle,page,page_x,page_y);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_FormFieldZOrderAtPoint(FPDF_FORMHANDLE hHandle,FPDF_PAGE page,double page_x,double page_y){
return FPDFPage_FormFieldZOrderAtPoint(hHandle,page,page_x,page_y);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_SetFormFieldHighlightColor(FPDF_FORMHANDLE hHandle,int fieldType,unsigned long color){
return FPDF_SetFormFieldHighlightColor(hHandle,fieldType,color);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_SetFormFieldHighlightAlpha(FPDF_FORMHANDLE hHandle,unsigned char alpha){
return FPDF_SetFormFieldHighlightAlpha(hHandle,alpha);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_RemoveFormFieldHighlight(FPDF_FORMHANDLE hHandle){
return FPDF_RemoveFormFieldHighlight(hHandle);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_FFLDraw(FPDF_FORMHANDLE hHandle,FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags){
return FPDF_FFLDraw(hHandle,bitmap,page,start_x,start_y,size_x,size_y,rotate,flags);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetFormType(FPDF_DOCUMENT document){
return FPDF_GetFormType(document);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_LoadXFA(FPDF_DOCUMENT document){
return FPDF_LoadXFA(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetSignatureCount(FPDF_DOCUMENT document){
return FPDF_GetSignatureCount(document);
}
FFI_PLUGIN_EXPORT FPDF_SIGNATURE PDFIUM_FPDF_GetSignatureObject(FPDF_DOCUMENT document,int index){
return FPDF_GetSignatureObject(document,index);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFSignatureObj_GetContents(FPDF_SIGNATURE signature,void * buffer,unsigned long length){
return FPDFSignatureObj_GetContents(signature,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFSignatureObj_GetByteRange(FPDF_SIGNATURE signature,int * buffer,unsigned long length){
return FPDFSignatureObj_GetByteRange(signature,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFSignatureObj_GetSubFilter(FPDF_SIGNATURE signature,char * buffer,unsigned long length){
return FPDFSignatureObj_GetSubFilter(signature,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFSignatureObj_GetReason(FPDF_SIGNATURE signature,void * buffer,unsigned long length){
return FPDFSignatureObj_GetReason(signature,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFSignatureObj_GetTime(FPDF_SIGNATURE signature,char * buffer,unsigned long length){
return FPDFSignatureObj_GetTime(signature,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned int PDFIUM_FPDFSignatureObj_GetDocMDPPermission(FPDF_SIGNATURE signature){
return FPDFSignatureObj_GetDocMDPPermission(signature);
}
FFI_PLUGIN_EXPORT FPDF_STRUCTTREE PDFIUM_FPDF_StructTree_GetForPage(FPDF_PAGE page){
return FPDF_StructTree_GetForPage(page);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_StructTree_Close(FPDF_STRUCTTREE struct_tree){
return FPDF_StructTree_Close(struct_tree);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructTree_CountChildren(FPDF_STRUCTTREE struct_tree){
return FPDF_StructTree_CountChildren(struct_tree);
}
FFI_PLUGIN_EXPORT FPDF_STRUCTELEMENT PDFIUM_FPDF_StructTree_GetChildAtIndex(FPDF_STRUCTTREE struct_tree,int index){
return FPDF_StructTree_GetChildAtIndex(struct_tree,index);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetAltText(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetAltText(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetActualText(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetActualText(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetID(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetID(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetLang(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetLang(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetStringAttribute(FPDF_STRUCTELEMENT struct_element,FPDF_BYTESTRING attr_name,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetStringAttribute(struct_element,attr_name,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_GetMarkedContentID(FPDF_STRUCTELEMENT struct_element){
return FPDF_StructElement_GetMarkedContentID(struct_element);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetType(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetType(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetObjType(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetObjType(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_StructElement_GetTitle(FPDF_STRUCTELEMENT struct_element,void * buffer,unsigned long buflen){
return FPDF_StructElement_GetTitle(struct_element,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_CountChildren(FPDF_STRUCTELEMENT struct_element){
return FPDF_StructElement_CountChildren(struct_element);
}
FFI_PLUGIN_EXPORT FPDF_STRUCTELEMENT PDFIUM_FPDF_StructElement_GetChildAtIndex(FPDF_STRUCTELEMENT struct_element,int index){
return FPDF_StructElement_GetChildAtIndex(struct_element,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_GetChildMarkedContentID(FPDF_STRUCTELEMENT struct_element,int index){
return FPDF_StructElement_GetChildMarkedContentID(struct_element,index);
}
FFI_PLUGIN_EXPORT FPDF_STRUCTELEMENT PDFIUM_FPDF_StructElement_GetParent(FPDF_STRUCTELEMENT struct_element){
return FPDF_StructElement_GetParent(struct_element);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_GetAttributeCount(FPDF_STRUCTELEMENT struct_element){
return FPDF_StructElement_GetAttributeCount(struct_element);
}
FFI_PLUGIN_EXPORT FPDF_STRUCTELEMENT_ATTR PDFIUM_FPDF_StructElement_GetAttributeAtIndex(FPDF_STRUCTELEMENT struct_element,int index){
return FPDF_StructElement_GetAttributeAtIndex(struct_element,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_Attr_GetCount(FPDF_STRUCTELEMENT_ATTR struct_attribute){
return FPDF_StructElement_Attr_GetCount(struct_attribute);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_StructElement_Attr_GetName(FPDF_STRUCTELEMENT_ATTR struct_attribute,int index,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDF_StructElement_Attr_GetName(struct_attribute,index,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_OBJECT_TYPE PDFIUM_FPDF_StructElement_Attr_GetType(FPDF_STRUCTELEMENT_ATTR struct_attribute,FPDF_BYTESTRING name){
return FPDF_StructElement_Attr_GetType(struct_attribute,name);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_StructElement_Attr_GetBooleanValue(FPDF_STRUCTELEMENT_ATTR struct_attribute,FPDF_BYTESTRING name,FPDF_BOOL * out_value){
return FPDF_StructElement_Attr_GetBooleanValue(struct_attribute,name,out_value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_StructElement_Attr_GetNumberValue(FPDF_STRUCTELEMENT_ATTR struct_attribute,FPDF_BYTESTRING name,float * out_value){
return FPDF_StructElement_Attr_GetNumberValue(struct_attribute,name,out_value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_StructElement_Attr_GetStringValue(FPDF_STRUCTELEMENT_ATTR struct_attribute,FPDF_BYTESTRING name,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDF_StructElement_Attr_GetStringValue(struct_attribute,name,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_StructElement_Attr_GetBlobValue(FPDF_STRUCTELEMENT_ATTR struct_attribute,FPDF_BYTESTRING name,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDF_StructElement_Attr_GetBlobValue(struct_attribute,name,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_GetMarkedContentIdCount(FPDF_STRUCTELEMENT struct_element){
return FPDF_StructElement_GetMarkedContentIdCount(struct_element);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_StructElement_GetMarkedContentIdAtIndex(FPDF_STRUCTELEMENT struct_element,int index){
return FPDF_StructElement_GetMarkedContentIdAtIndex(struct_element,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_ImportPagesByIndex(FPDF_DOCUMENT dest_doc,FPDF_DOCUMENT src_doc,const int * page_indices,unsigned long length,int index){
return FPDF_ImportPagesByIndex(dest_doc,src_doc,page_indices,length,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_ImportPages(FPDF_DOCUMENT dest_doc,FPDF_DOCUMENT src_doc,FPDF_BYTESTRING pagerange,int index){
return FPDF_ImportPages(dest_doc,src_doc,pagerange,index);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_ImportNPagesToOne(FPDF_DOCUMENT src_doc,float output_width,float output_height,size_t num_pages_on_x_axis,size_t num_pages_on_y_axis){
return FPDF_ImportNPagesToOne(src_doc,output_width,output_height,num_pages_on_x_axis,num_pages_on_y_axis);
}
FFI_PLUGIN_EXPORT FPDF_XOBJECT PDFIUM_FPDF_NewXObjectFromPage(FPDF_DOCUMENT dest_doc,FPDF_DOCUMENT src_doc,int src_page_index){
return FPDF_NewXObjectFromPage(dest_doc,src_doc,src_page_index);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_CloseXObject(FPDF_XOBJECT xobject){
return FPDF_CloseXObject(xobject);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDF_NewFormObjectFromXObject(FPDF_XOBJECT xobject){
return FPDF_NewFormObjectFromXObject(xobject);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_CopyViewerPreferences(FPDF_DOCUMENT dest_doc,FPDF_DOCUMENT src_doc){
return FPDF_CopyViewerPreferences(dest_doc,src_doc);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_InitLibraryWithConfig(const FPDF_LIBRARY_CONFIG * config){
return FPDF_InitLibraryWithConfig(config);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_InitLibrary(){
return FPDF_InitLibrary();
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_DestroyLibrary(){
return FPDF_DestroyLibrary();
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_SetSandBoxPolicy(FPDF_DWORD policy,FPDF_BOOL enable){
return FPDF_SetSandBoxPolicy(policy,enable);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_LoadDocument(FPDF_STRING file_path,FPDF_BYTESTRING password){
return FPDF_LoadDocument(file_path,password);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_LoadMemDocument(const void * data_buf,int size,FPDF_BYTESTRING password){
return FPDF_LoadMemDocument(data_buf,size,password);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_LoadMemDocument64(const void * data_buf,size_t size,FPDF_BYTESTRING password){
return FPDF_LoadMemDocument64(data_buf,size,password);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_LoadCustomDocument(FPDF_FILEACCESS * pFileAccess,FPDF_BYTESTRING password){
return FPDF_LoadCustomDocument(pFileAccess,password);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_GetFileVersion(FPDF_DOCUMENT doc,int * fileVersion){
return FPDF_GetFileVersion(doc,fileVersion);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetLastError(){
return FPDF_GetLastError();
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_DocumentHasValidCrossReferenceTable(FPDF_DOCUMENT document){
return FPDF_DocumentHasValidCrossReferenceTable(document);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetTrailerEnds(FPDF_DOCUMENT document,unsigned int * buffer,unsigned long length){
return FPDF_GetTrailerEnds(document,buffer,length);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetDocPermissions(FPDF_DOCUMENT document){
return FPDF_GetDocPermissions(document);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetDocUserPermissions(FPDF_DOCUMENT document){
return FPDF_GetDocUserPermissions(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetSecurityHandlerRevision(FPDF_DOCUMENT document){
return FPDF_GetSecurityHandlerRevision(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetPageCount(FPDF_DOCUMENT document){
return FPDF_GetPageCount(document);
}
FFI_PLUGIN_EXPORT FPDF_PAGE PDFIUM_FPDF_LoadPage(FPDF_DOCUMENT document,int page_index){
return FPDF_LoadPage(document,page_index);
}
FFI_PLUGIN_EXPORT float PDFIUM_FPDF_GetPageWidthF(FPDF_PAGE page){
return FPDF_GetPageWidthF(page);
}
FFI_PLUGIN_EXPORT double PDFIUM_FPDF_GetPageWidth(FPDF_PAGE page){
return FPDF_GetPageWidth(page);
}
FFI_PLUGIN_EXPORT float PDFIUM_FPDF_GetPageHeightF(FPDF_PAGE page){
return FPDF_GetPageHeightF(page);
}
FFI_PLUGIN_EXPORT double PDFIUM_FPDF_GetPageHeight(FPDF_PAGE page){
return FPDF_GetPageHeight(page);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_GetPageBoundingBox(FPDF_PAGE page,FS_RECTF * rect){
return FPDF_GetPageBoundingBox(page,rect);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_GetPageSizeByIndexF(FPDF_DOCUMENT document,int page_index,FS_SIZEF * size){
return FPDF_GetPageSizeByIndexF(document,page_index,size);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetPageSizeByIndex(FPDF_DOCUMENT document,int page_index,double * width,double * height){
return FPDF_GetPageSizeByIndex(document,page_index,width,height);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_RenderPageBitmap(FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags){
return FPDF_RenderPageBitmap(bitmap,page,start_x,start_y,size_x,size_y,rotate,flags);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_RenderPageBitmapWithMatrix(FPDF_BITMAP bitmap,FPDF_PAGE page,const FS_MATRIX * matrix,const FS_RECTF * clipping,int flags){
return FPDF_RenderPageBitmapWithMatrix(bitmap,page,matrix,clipping,flags);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_ClosePage(FPDF_PAGE page){
return FPDF_ClosePage(page);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_CloseDocument(FPDF_DOCUMENT document){
return FPDF_CloseDocument(document);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_DeviceToPage(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int device_x,int device_y,double * page_x,double * page_y){
return FPDF_DeviceToPage(page,start_x,start_y,size_x,size_y,rotate,device_x,device_y,page_x,page_y);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_PageToDevice(FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,double page_x,double page_y,int * device_x,int * device_y){
return FPDF_PageToDevice(page,start_x,start_y,size_x,size_y,rotate,page_x,page_y,device_x,device_y);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFBitmap_Create(int width,int height,int alpha){
return FPDFBitmap_Create(width,height,alpha);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFBitmap_CreateEx(int width,int height,int format,void * first_scan,int stride){
return FPDFBitmap_CreateEx(width,height,format,first_scan,stride);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFBitmap_GetFormat(FPDF_BITMAP bitmap){
return FPDFBitmap_GetFormat(bitmap);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFBitmap_FillRect(FPDF_BITMAP bitmap,int left,int top,int width,int height,FPDF_DWORD color){
return FPDFBitmap_FillRect(bitmap,left,top,width,height,color);
}
FFI_PLUGIN_EXPORT void * PDFIUM_FPDFBitmap_GetBuffer(FPDF_BITMAP bitmap){
return FPDFBitmap_GetBuffer(bitmap);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFBitmap_GetWidth(FPDF_BITMAP bitmap){
return FPDFBitmap_GetWidth(bitmap);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFBitmap_GetHeight(FPDF_BITMAP bitmap){
return FPDFBitmap_GetHeight(bitmap);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFBitmap_GetStride(FPDF_BITMAP bitmap){
return FPDFBitmap_GetStride(bitmap);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFBitmap_Destroy(FPDF_BITMAP bitmap){
return FPDFBitmap_Destroy(bitmap);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_VIEWERREF_GetPrintScaling(FPDF_DOCUMENT document){
return FPDF_VIEWERREF_GetPrintScaling(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_VIEWERREF_GetNumCopies(FPDF_DOCUMENT document){
return FPDF_VIEWERREF_GetNumCopies(document);
}
FFI_PLUGIN_EXPORT FPDF_PAGERANGE PDFIUM_FPDF_VIEWERREF_GetPrintPageRange(FPDF_DOCUMENT document){
return FPDF_VIEWERREF_GetPrintPageRange(document);
}
FFI_PLUGIN_EXPORT size_t PDFIUM_FPDF_VIEWERREF_GetPrintPageRangeCount(FPDF_PAGERANGE pagerange){
return FPDF_VIEWERREF_GetPrintPageRangeCount(pagerange);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_VIEWERREF_GetPrintPageRangeElement(FPDF_PAGERANGE pagerange,size_t index){
return FPDF_VIEWERREF_GetPrintPageRangeElement(pagerange,index);
}
FFI_PLUGIN_EXPORT FPDF_DUPLEXTYPE PDFIUM_FPDF_VIEWERREF_GetDuplex(FPDF_DOCUMENT document){
return FPDF_VIEWERREF_GetDuplex(document);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_VIEWERREF_GetName(FPDF_DOCUMENT document,FPDF_BYTESTRING key,char * buffer,unsigned long length){
return FPDF_VIEWERREF_GetName(document,key,buffer,length);
}
FFI_PLUGIN_EXPORT FPDF_DWORD PDFIUM_FPDF_CountNamedDests(FPDF_DOCUMENT document){
return FPDF_CountNamedDests(document);
}
FFI_PLUGIN_EXPORT FPDF_DEST PDFIUM_FPDF_GetNamedDestByName(FPDF_DOCUMENT document,FPDF_BYTESTRING name){
return FPDF_GetNamedDestByName(document,name);
}
FFI_PLUGIN_EXPORT FPDF_DEST PDFIUM_FPDF_GetNamedDest(FPDF_DOCUMENT document,int index,void * buffer,long * buflen){
return FPDF_GetNamedDest(document,index,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_GetXFAPacketCount(FPDF_DOCUMENT document){
return FPDF_GetXFAPacketCount(document);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDF_GetXFAPacketName(FPDF_DOCUMENT document,int index,void * buffer,unsigned long buflen){
return FPDF_GetXFAPacketName(document,index,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_GetXFAPacketContent(FPDF_DOCUMENT document,int index,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDF_GetXFAPacketContent(document,index,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFCatalog_IsTagged(FPDF_DOCUMENT document){
return FPDFCatalog_IsTagged(document);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDF_CreateNewDocument(){
return FPDF_CreateNewDocument();
}
FFI_PLUGIN_EXPORT FPDF_PAGE PDFIUM_FPDFPage_New(FPDF_DOCUMENT document,int page_index,double width,double height){
return FPDFPage_New(document,page_index,width,height);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_Delete(FPDF_DOCUMENT document,int page_index){
return FPDFPage_Delete(document,page_index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDF_MovePages(FPDF_DOCUMENT document,const int * page_indices,unsigned long page_indices_len,int dest_page_index){
return FPDF_MovePages(document,page_indices,page_indices_len,dest_page_index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_GetRotation(FPDF_PAGE page){
return FPDFPage_GetRotation(page);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_SetRotation(FPDF_PAGE page,int rotate){
return FPDFPage_SetRotation(page,rotate);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_InsertObject(FPDF_PAGE page,FPDF_PAGEOBJECT page_object){
return FPDFPage_InsertObject(page,page_object);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_RemoveObject(FPDF_PAGE page,FPDF_PAGEOBJECT page_object){
return FPDFPage_RemoveObject(page,page_object);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPage_CountObjects(FPDF_PAGE page){
return FPDFPage_CountObjects(page);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPage_GetObject(FPDF_PAGE page,int index){
return FPDFPage_GetObject(page,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_HasTransparency(FPDF_PAGE page){
return FPDFPage_HasTransparency(page);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPage_GenerateContent(FPDF_PAGE page){
return FPDFPage_GenerateContent(page);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPageObj_Destroy(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_Destroy(page_object);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_HasTransparency(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_HasTransparency(page_object);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObj_GetType(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_GetType(page_object);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPageObj_Transform(FPDF_PAGEOBJECT page_object,double a,double b,double c,double d,double e,double f){
return FPDFPageObj_Transform(page_object,a,b,c,d,e,f);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetMatrix(FPDF_PAGEOBJECT page_object,FS_MATRIX * matrix){
return FPDFPageObj_GetMatrix(page_object,matrix);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetMatrix(FPDF_PAGEOBJECT page_object,const FS_MATRIX * matrix){
return FPDFPageObj_SetMatrix(page_object,matrix);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPage_TransformAnnots(FPDF_PAGE page,double a,double b,double c,double d,double e,double f){
return FPDFPage_TransformAnnots(page,a,b,c,d,e,f);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPageObj_NewImageObj(FPDF_DOCUMENT document){
return FPDFPageObj_NewImageObj(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObj_CountMarks(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_CountMarks(page_object);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECTMARK PDFIUM_FPDFPageObj_GetMark(FPDF_PAGEOBJECT page_object,unsigned long index){
return FPDFPageObj_GetMark(page_object,index);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECTMARK PDFIUM_FPDFPageObj_AddMark(FPDF_PAGEOBJECT page_object,FPDF_BYTESTRING name){
return FPDFPageObj_AddMark(page_object,name);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_RemoveMark(FPDF_PAGEOBJECT page_object,FPDF_PAGEOBJECTMARK mark){
return FPDFPageObj_RemoveMark(page_object,mark);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_GetName(FPDF_PAGEOBJECTMARK mark,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDFPageObjMark_GetName(mark,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObjMark_CountParams(FPDF_PAGEOBJECTMARK mark){
return FPDFPageObjMark_CountParams(mark);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_GetParamKey(FPDF_PAGEOBJECTMARK mark,unsigned long index,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDFPageObjMark_GetParamKey(mark,index,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_OBJECT_TYPE PDFIUM_FPDFPageObjMark_GetParamValueType(FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key){
return FPDFPageObjMark_GetParamValueType(mark,key);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_GetParamIntValue(FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,int * out_value){
return FPDFPageObjMark_GetParamIntValue(mark,key,out_value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_GetParamStringValue(FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDFPageObjMark_GetParamStringValue(mark,key,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_GetParamBlobValue(FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDFPageObjMark_GetParamBlobValue(mark,key,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_SetIntParam(FPDF_DOCUMENT document,FPDF_PAGEOBJECT page_object,FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,int value){
return FPDFPageObjMark_SetIntParam(document,page_object,mark,key,value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_SetStringParam(FPDF_DOCUMENT document,FPDF_PAGEOBJECT page_object,FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,FPDF_BYTESTRING value){
return FPDFPageObjMark_SetStringParam(document,page_object,mark,key,value);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_SetBlobParam(FPDF_DOCUMENT document,FPDF_PAGEOBJECT page_object,FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key,void * value,unsigned long value_len){
return FPDFPageObjMark_SetBlobParam(document,page_object,mark,key,value,value_len);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObjMark_RemoveParam(FPDF_PAGEOBJECT page_object,FPDF_PAGEOBJECTMARK mark,FPDF_BYTESTRING key){
return FPDFPageObjMark_RemoveParam(page_object,mark,key);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_LoadJpegFile(FPDF_PAGE * pages,int count,FPDF_PAGEOBJECT image_object,FPDF_FILEACCESS * file_access){
return FPDFImageObj_LoadJpegFile(pages,count,image_object,file_access);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_LoadJpegFileInline(FPDF_PAGE * pages,int count,FPDF_PAGEOBJECT image_object,FPDF_FILEACCESS * file_access){
return FPDFImageObj_LoadJpegFileInline(pages,count,image_object,file_access);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_SetMatrix(FPDF_PAGEOBJECT image_object,double a,double b,double c,double d,double e,double f){
return FPDFImageObj_SetMatrix(image_object,a,b,c,d,e,f);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_SetBitmap(FPDF_PAGE * pages,int count,FPDF_PAGEOBJECT image_object,FPDF_BITMAP bitmap){
return FPDFImageObj_SetBitmap(pages,count,image_object,bitmap);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFImageObj_GetBitmap(FPDF_PAGEOBJECT image_object){
return FPDFImageObj_GetBitmap(image_object);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFImageObj_GetRenderedBitmap(FPDF_DOCUMENT document,FPDF_PAGE page,FPDF_PAGEOBJECT image_object){
return FPDFImageObj_GetRenderedBitmap(document,page,image_object);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFImageObj_GetImageDataDecoded(FPDF_PAGEOBJECT image_object,void * buffer,unsigned long buflen){
return FPDFImageObj_GetImageDataDecoded(image_object,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFImageObj_GetImageDataRaw(FPDF_PAGEOBJECT image_object,void * buffer,unsigned long buflen){
return FPDFImageObj_GetImageDataRaw(image_object,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFImageObj_GetImageFilterCount(FPDF_PAGEOBJECT image_object){
return FPDFImageObj_GetImageFilterCount(image_object);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFImageObj_GetImageFilter(FPDF_PAGEOBJECT image_object,int index,void * buffer,unsigned long buflen){
return FPDFImageObj_GetImageFilter(image_object,index,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_GetImageMetadata(FPDF_PAGEOBJECT image_object,FPDF_PAGE page,FPDF_IMAGEOBJ_METADATA * metadata){
return FPDFImageObj_GetImageMetadata(image_object,page,metadata);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFImageObj_GetImagePixelSize(FPDF_PAGEOBJECT image_object,unsigned int * width,unsigned int * height){
return FPDFImageObj_GetImagePixelSize(image_object,width,height);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPageObj_CreateNewPath(float x,float y){
return FPDFPageObj_CreateNewPath(x,y);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPageObj_CreateNewRect(float x,float y,float w,float h){
return FPDFPageObj_CreateNewRect(x,y,w,h);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetBounds(FPDF_PAGEOBJECT page_object,float * left,float * bottom,float * right,float * top){
return FPDFPageObj_GetBounds(page_object,left,bottom,right,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetRotatedBounds(FPDF_PAGEOBJECT page_object,FS_QUADPOINTSF * quad_points){
return FPDFPageObj_GetRotatedBounds(page_object,quad_points);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFPageObj_SetBlendMode(FPDF_PAGEOBJECT page_object,FPDF_BYTESTRING blend_mode){
return FPDFPageObj_SetBlendMode(page_object,blend_mode);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetStrokeColor(FPDF_PAGEOBJECT page_object,unsigned int R,unsigned int G,unsigned int B,unsigned int A){
return FPDFPageObj_SetStrokeColor(page_object,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetStrokeColor(FPDF_PAGEOBJECT page_object,unsigned int * R,unsigned int * G,unsigned int * B,unsigned int * A){
return FPDFPageObj_GetStrokeColor(page_object,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetStrokeWidth(FPDF_PAGEOBJECT page_object,float width){
return FPDFPageObj_SetStrokeWidth(page_object,width);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetStrokeWidth(FPDF_PAGEOBJECT page_object,float * width){
return FPDFPageObj_GetStrokeWidth(page_object,width);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObj_GetLineJoin(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_GetLineJoin(page_object);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetLineJoin(FPDF_PAGEOBJECT page_object,int line_join){
return FPDFPageObj_SetLineJoin(page_object,line_join);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObj_GetLineCap(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_GetLineCap(page_object);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetLineCap(FPDF_PAGEOBJECT page_object,int line_cap){
return FPDFPageObj_SetLineCap(page_object,line_cap);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetFillColor(FPDF_PAGEOBJECT page_object,unsigned int R,unsigned int G,unsigned int B,unsigned int A){
return FPDFPageObj_SetFillColor(page_object,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetFillColor(FPDF_PAGEOBJECT page_object,unsigned int * R,unsigned int * G,unsigned int * B,unsigned int * A){
return FPDFPageObj_GetFillColor(page_object,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetDashPhase(FPDF_PAGEOBJECT page_object,float * phase){
return FPDFPageObj_GetDashPhase(page_object,phase);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetDashPhase(FPDF_PAGEOBJECT page_object,float phase){
return FPDFPageObj_SetDashPhase(page_object,phase);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPageObj_GetDashCount(FPDF_PAGEOBJECT page_object){
return FPDFPageObj_GetDashCount(page_object);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_GetDashArray(FPDF_PAGEOBJECT page_object,float * dash_array,size_t dash_count){
return FPDFPageObj_GetDashArray(page_object,dash_array,dash_count);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPageObj_SetDashArray(FPDF_PAGEOBJECT page_object,const float * dash_array,size_t dash_count,float phase){
return FPDFPageObj_SetDashArray(page_object,dash_array,dash_count,phase);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPath_CountSegments(FPDF_PAGEOBJECT path){
return FPDFPath_CountSegments(path);
}
FFI_PLUGIN_EXPORT FPDF_PATHSEGMENT PDFIUM_FPDFPath_GetPathSegment(FPDF_PAGEOBJECT path,int index){
return FPDFPath_GetPathSegment(path,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPathSegment_GetPoint(FPDF_PATHSEGMENT segment,float * x,float * y){
return FPDFPathSegment_GetPoint(segment,x,y);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFPathSegment_GetType(FPDF_PATHSEGMENT segment){
return FPDFPathSegment_GetType(segment);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPathSegment_GetClose(FPDF_PATHSEGMENT segment){
return FPDFPathSegment_GetClose(segment);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_MoveTo(FPDF_PAGEOBJECT path,float x,float y){
return FPDFPath_MoveTo(path,x,y);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_LineTo(FPDF_PAGEOBJECT path,float x,float y){
return FPDFPath_LineTo(path,x,y);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_BezierTo(FPDF_PAGEOBJECT path,float x1,float y1,float x2,float y2,float x3,float y3){
return FPDFPath_BezierTo(path,x1,y1,x2,y2,x3,y3);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_Close(FPDF_PAGEOBJECT path){
return FPDFPath_Close(path);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_SetDrawMode(FPDF_PAGEOBJECT path,int fillmode,FPDF_BOOL stroke){
return FPDFPath_SetDrawMode(path,fillmode,stroke);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFPath_GetDrawMode(FPDF_PAGEOBJECT path,int * fillmode,FPDF_BOOL * stroke){
return FPDFPath_GetDrawMode(path,fillmode,stroke);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPageObj_NewTextObj(FPDF_DOCUMENT document,FPDF_BYTESTRING font,float font_size){
return FPDFPageObj_NewTextObj(document,font,font_size);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_SetText(FPDF_PAGEOBJECT text_object,FPDF_WIDESTRING text){
return FPDFText_SetText(text_object,text);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_SetCharcodes(FPDF_PAGEOBJECT text_object,const uint32_t * charcodes,size_t count){
return FPDFText_SetCharcodes(text_object,charcodes,count);
}
FFI_PLUGIN_EXPORT FPDF_FONT PDFIUM_FPDFText_LoadFont(FPDF_DOCUMENT document,const uint8_t * data,uint32_t size,int font_type,FPDF_BOOL cid){
return FPDFText_LoadFont(document,data,size,font_type,cid);
}
FFI_PLUGIN_EXPORT FPDF_FONT PDFIUM_FPDFText_LoadStandardFont(FPDF_DOCUMENT document,FPDF_BYTESTRING font){
return FPDFText_LoadStandardFont(document,font);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFTextObj_GetFontSize(FPDF_PAGEOBJECT text,float * size){
return FPDFTextObj_GetFontSize(text,size);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFFont_Close(FPDF_FONT font){
return FPDFFont_Close(font);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFPageObj_CreateTextObj(FPDF_DOCUMENT document,FPDF_FONT font,float font_size){
return FPDFPageObj_CreateTextObj(document,font,font_size);
}
FFI_PLUGIN_EXPORT FPDF_TEXT_RENDERMODE PDFIUM_FPDFTextObj_GetTextRenderMode(FPDF_PAGEOBJECT text){
return FPDFTextObj_GetTextRenderMode(text);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFTextObj_SetTextRenderMode(FPDF_PAGEOBJECT text,FPDF_TEXT_RENDERMODE render_mode){
return FPDFTextObj_SetTextRenderMode(text,render_mode);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFTextObj_GetText(FPDF_PAGEOBJECT text_object,FPDF_TEXTPAGE text_page,FPDF_WCHAR * buffer,unsigned long length){
return FPDFTextObj_GetText(text_object,text_page,buffer,length);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFTextObj_GetRenderedBitmap(FPDF_DOCUMENT document,FPDF_PAGE page,FPDF_PAGEOBJECT text_object,float scale){
return FPDFTextObj_GetRenderedBitmap(document,page,text_object,scale);
}
FFI_PLUGIN_EXPORT FPDF_FONT PDFIUM_FPDFTextObj_GetFont(FPDF_PAGEOBJECT text){
return FPDFTextObj_GetFont(text);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFFont_GetFontName(FPDF_FONT font,char * buffer,unsigned long length){
return FPDFFont_GetFontName(font,buffer,length);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFFont_GetFontData(FPDF_FONT font,uint8_t * buffer,size_t buflen,size_t * out_buflen){
return FPDFFont_GetFontData(font,buffer,buflen,out_buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFFont_GetIsEmbedded(FPDF_FONT font){
return FPDFFont_GetIsEmbedded(font);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFFont_GetFlags(FPDF_FONT font){
return FPDFFont_GetFlags(font);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFFont_GetWeight(FPDF_FONT font){
return FPDFFont_GetWeight(font);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFFont_GetItalicAngle(FPDF_FONT font,int * angle){
return FPDFFont_GetItalicAngle(font,angle);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFFont_GetAscent(FPDF_FONT font,float font_size,float * ascent){
return FPDFFont_GetAscent(font,font_size,ascent);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFFont_GetDescent(FPDF_FONT font,float font_size,float * descent){
return FPDFFont_GetDescent(font,font_size,descent);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFFont_GetGlyphWidth(FPDF_FONT font,uint32_t glyph,float font_size,float * width){
return FPDFFont_GetGlyphWidth(font,glyph,font_size,width);
}
FFI_PLUGIN_EXPORT FPDF_GLYPHPATH PDFIUM_FPDFFont_GetGlyphPath(FPDF_FONT font,uint32_t glyph,float font_size){
return FPDFFont_GetGlyphPath(font,glyph,font_size);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFGlyphPath_CountGlyphSegments(FPDF_GLYPHPATH glyphpath){
return FPDFGlyphPath_CountGlyphSegments(glyphpath);
}
FFI_PLUGIN_EXPORT FPDF_PATHSEGMENT PDFIUM_FPDFGlyphPath_GetGlyphPathSegment(FPDF_GLYPHPATH glyphpath,int index){
return FPDFGlyphPath_GetGlyphPathSegment(glyphpath,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFFormObj_CountObjects(FPDF_PAGEOBJECT form_object){
return FPDFFormObj_CountObjects(form_object);
}
FFI_PLUGIN_EXPORT FPDF_PAGEOBJECT PDFIUM_FPDFFormObj_GetObject(FPDF_PAGEOBJECT form_object,unsigned long index){
return FPDFFormObj_GetObject(form_object,index);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFPage_GetDecodedThumbnailData(FPDF_PAGE page,void * buffer,unsigned long buflen){
return FPDFPage_GetDecodedThumbnailData(page,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFPage_GetRawThumbnailData(FPDF_PAGE page,void * buffer,unsigned long buflen){
return FPDFPage_GetRawThumbnailData(page,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BITMAP PDFIUM_FPDFPage_GetThumbnailAsBitmap(FPDF_PAGE page){
return FPDFPage_GetThumbnailAsBitmap(page);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFDoc_GetJavaScriptActionCount(FPDF_DOCUMENT document){
return FPDFDoc_GetJavaScriptActionCount(document);
}
FFI_PLUGIN_EXPORT FPDF_JAVASCRIPT_ACTION PDFIUM_FPDFDoc_GetJavaScriptAction(FPDF_DOCUMENT document,int index){
return FPDFDoc_GetJavaScriptAction(document,index);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFDoc_CloseJavaScriptAction(FPDF_JAVASCRIPT_ACTION javascript){
return FPDFDoc_CloseJavaScriptAction(javascript);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFJavaScriptAction_GetName(FPDF_JAVASCRIPT_ACTION javascript,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFJavaScriptAction_GetName(javascript,buffer,buflen);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFJavaScriptAction_GetScript(FPDF_JAVASCRIPT_ACTION javascript,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFJavaScriptAction_GetScript(javascript,buffer,buflen);
}
FFI_PLUGIN_EXPORT const FPDF_CharsetFontMap * PDFIUM_FPDF_GetDefaultTTFMap(){
return FPDF_GetDefaultTTFMap();
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_AddInstalledFont(void * mapper,const char * face,int charset){
return FPDF_AddInstalledFont(mapper,face,charset);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_SetSystemFontInfo(FPDF_SYSFONTINFO * pFontInfo){
return FPDF_SetSystemFontInfo(pFontInfo);
}
FFI_PLUGIN_EXPORT FPDF_SYSFONTINFO * PDFIUM_FPDF_GetDefaultSystemFontInfo(){
return FPDF_GetDefaultSystemFontInfo();
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_FreeDefaultSystemFontInfo(FPDF_SYSFONTINFO * pFontInfo){
return FPDF_FreeDefaultSystemFontInfo(pFontInfo);
}
FFI_PLUGIN_EXPORT FPDF_AVAIL PDFIUM_FPDFAvail_Create(FX_FILEAVAIL * file_avail,FPDF_FILEACCESS * file){
return FPDFAvail_Create(file_avail,file);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFAvail_Destroy(FPDF_AVAIL avail){
return FPDFAvail_Destroy(avail);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAvail_IsDocAvail(FPDF_AVAIL avail,FX_DOWNLOADHINTS * hints){
return FPDFAvail_IsDocAvail(avail,hints);
}
FFI_PLUGIN_EXPORT FPDF_DOCUMENT PDFIUM_FPDFAvail_GetDocument(FPDF_AVAIL avail,FPDF_BYTESTRING password){
return FPDFAvail_GetDocument(avail,password);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAvail_GetFirstPageNum(FPDF_DOCUMENT doc){
return FPDFAvail_GetFirstPageNum(doc);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAvail_IsPageAvail(FPDF_AVAIL avail,int page_index,FX_DOWNLOADHINTS * hints){
return FPDFAvail_IsPageAvail(avail,page_index,hints);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAvail_IsFormAvail(FPDF_AVAIL avail,FX_DOWNLOADHINTS * hints){
return FPDFAvail_IsFormAvail(avail,hints);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFAvail_IsLinearized(FPDF_AVAIL avail){
return FPDFAvail_IsLinearized(avail);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_RenderPageBitmapWithColorScheme_Start(FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags,const FPDF_COLORSCHEME * color_scheme,IFSDK_PAUSE * pause){
return FPDF_RenderPageBitmapWithColorScheme_Start(bitmap,page,start_x,start_y,size_x,size_y,rotate,flags,color_scheme,pause);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_RenderPageBitmap_Start(FPDF_BITMAP bitmap,FPDF_PAGE page,int start_x,int start_y,int size_x,int size_y,int rotate,int flags,IFSDK_PAUSE * pause){
return FPDF_RenderPageBitmap_Start(bitmap,page,start_x,start_y,size_x,size_y,rotate,flags,pause);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDF_RenderPage_Continue(FPDF_PAGE page,IFSDK_PAUSE * pause){
return FPDF_RenderPage_Continue(page,pause);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDF_RenderPage_Close(FPDF_PAGE page){
return FPDF_RenderPage_Close(page);
}
FFI_PLUGIN_EXPORT FPDF_TEXTPAGE PDFIUM_FPDFText_LoadPage(FPDF_PAGE page){
return FPDFText_LoadPage(page);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFText_ClosePage(FPDF_TEXTPAGE text_page){
return FPDFText_ClosePage(text_page);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_CountChars(FPDF_TEXTPAGE text_page){
return FPDFText_CountChars(text_page);
}
FFI_PLUGIN_EXPORT unsigned int PDFIUM_FPDFText_GetUnicode(FPDF_TEXTPAGE text_page,int index){
return FPDFText_GetUnicode(text_page,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_IsGenerated(FPDF_TEXTPAGE text_page,int index){
return FPDFText_IsGenerated(text_page,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_IsHyphen(FPDF_TEXTPAGE text_page,int index){
return FPDFText_IsHyphen(text_page,index);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_HasUnicodeMapError(FPDF_TEXTPAGE text_page,int index){
return FPDFText_HasUnicodeMapError(text_page,index);
}
FFI_PLUGIN_EXPORT double PDFIUM_FPDFText_GetFontSize(FPDF_TEXTPAGE text_page,int index){
return FPDFText_GetFontSize(text_page,index);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFText_GetFontInfo(FPDF_TEXTPAGE text_page,int index,void * buffer,unsigned long buflen,int * flags){
return FPDFText_GetFontInfo(text_page,index,buffer,buflen,flags);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetFontWeight(FPDF_TEXTPAGE text_page,int index){
return FPDFText_GetFontWeight(text_page,index);
}
FFI_PLUGIN_EXPORT FPDF_TEXT_RENDERMODE PDFIUM_FPDFText_GetTextRenderMode(FPDF_TEXTPAGE text_page,int index){
return FPDFText_GetTextRenderMode(text_page,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetFillColor(FPDF_TEXTPAGE text_page,int index,unsigned int * R,unsigned int * G,unsigned int * B,unsigned int * A){
return FPDFText_GetFillColor(text_page,index,R,G,B,A);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetStrokeColor(FPDF_TEXTPAGE text_page,int index,unsigned int * R,unsigned int * G,unsigned int * B,unsigned int * A){
return FPDFText_GetStrokeColor(text_page,index,R,G,B,A);
}
FFI_PLUGIN_EXPORT float PDFIUM_FPDFText_GetCharAngle(FPDF_TEXTPAGE text_page,int index){
return FPDFText_GetCharAngle(text_page,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetCharBox(FPDF_TEXTPAGE text_page,int index,double * left,double * right,double * bottom,double * top){
return FPDFText_GetCharBox(text_page,index,left,right,bottom,top);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetLooseCharBox(FPDF_TEXTPAGE text_page,int index,FS_RECTF * rect){
return FPDFText_GetLooseCharBox(text_page,index,rect);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetMatrix(FPDF_TEXTPAGE text_page,int index,FS_MATRIX * matrix){
return FPDFText_GetMatrix(text_page,index,matrix);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetCharOrigin(FPDF_TEXTPAGE text_page,int index,double * x,double * y){
return FPDFText_GetCharOrigin(text_page,index,x,y);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetCharIndexAtPos(FPDF_TEXTPAGE text_page,double x,double y,double xTolerance,double yTolerance){
return FPDFText_GetCharIndexAtPos(text_page,x,y,xTolerance,yTolerance);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetText(FPDF_TEXTPAGE text_page,int start_index,int count,unsigned short * result){
return FPDFText_GetText(text_page,start_index,count,result);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_CountRects(FPDF_TEXTPAGE text_page,int start_index,int count){
return FPDFText_CountRects(text_page,start_index,count);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_GetRect(FPDF_TEXTPAGE text_page,int rect_index,double * left,double * top,double * right,double * bottom){
return FPDFText_GetRect(text_page,rect_index,left,top,right,bottom);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetBoundedText(FPDF_TEXTPAGE text_page,double left,double top,double right,double bottom,unsigned short * buffer,int buflen){
return FPDFText_GetBoundedText(text_page,left,top,right,bottom,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_SCHHANDLE PDFIUM_FPDFText_FindStart(FPDF_TEXTPAGE text_page,FPDF_WIDESTRING findwhat,unsigned long flags,int start_index){
return FPDFText_FindStart(text_page,findwhat,flags,start_index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_FindNext(FPDF_SCHHANDLE handle){
return FPDFText_FindNext(handle);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFText_FindPrev(FPDF_SCHHANDLE handle){
return FPDFText_FindPrev(handle);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetSchResultIndex(FPDF_SCHHANDLE handle){
return FPDFText_GetSchResultIndex(handle);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFText_GetSchCount(FPDF_SCHHANDLE handle){
return FPDFText_GetSchCount(handle);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFText_FindClose(FPDF_SCHHANDLE handle){
return FPDFText_FindClose(handle);
}
FFI_PLUGIN_EXPORT FPDF_PAGELINK PDFIUM_FPDFLink_LoadWebLinks(FPDF_TEXTPAGE text_page){
return FPDFLink_LoadWebLinks(text_page);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFLink_CountWebLinks(FPDF_PAGELINK link_page){
return FPDFLink_CountWebLinks(link_page);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFLink_GetURL(FPDF_PAGELINK link_page,int link_index,unsigned short * buffer,int buflen){
return FPDFLink_GetURL(link_page,link_index,buffer,buflen);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFLink_CountRects(FPDF_PAGELINK link_page,int link_index){
return FPDFLink_CountRects(link_page,link_index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFLink_GetRect(FPDF_PAGELINK link_page,int link_index,int rect_index,double * left,double * top,double * right,double * bottom){
return FPDFLink_GetRect(link_page,link_index,rect_index,left,top,right,bottom);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFLink_GetTextRange(FPDF_PAGELINK link_page,int link_index,int * start_char_index,int * char_count){
return FPDFLink_GetTextRange(link_page,link_index,start_char_index,char_count);
}
FFI_PLUGIN_EXPORT void PDFIUM_FPDFLink_CloseWebLinks(FPDF_PAGELINK link_page){
return FPDFLink_CloseWebLinks(link_page);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFDoc_GetPageMode(FPDF_DOCUMENT document){
return FPDFDoc_GetPageMode(document);
}
FFI_PLUGIN_EXPORT int PDFIUM_FPDFDoc_GetAttachmentCount(FPDF_DOCUMENT document){
return FPDFDoc_GetAttachmentCount(document);
}
FFI_PLUGIN_EXPORT FPDF_ATTACHMENT PDFIUM_FPDFDoc_AddAttachment(FPDF_DOCUMENT document,FPDF_WIDESTRING name){
return FPDFDoc_AddAttachment(document,name);
}
FFI_PLUGIN_EXPORT FPDF_ATTACHMENT PDFIUM_FPDFDoc_GetAttachment(FPDF_DOCUMENT document,int index){
return FPDFDoc_GetAttachment(document,index);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFDoc_DeleteAttachment(FPDF_DOCUMENT document,int index){
return FPDFDoc_DeleteAttachment(document,index);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAttachment_GetName(FPDF_ATTACHMENT attachment,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAttachment_GetName(attachment,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAttachment_HasKey(FPDF_ATTACHMENT attachment,FPDF_BYTESTRING key){
return FPDFAttachment_HasKey(attachment,key);
}
FFI_PLUGIN_EXPORT FPDF_OBJECT_TYPE PDFIUM_FPDFAttachment_GetValueType(FPDF_ATTACHMENT attachment,FPDF_BYTESTRING key){
return FPDFAttachment_GetValueType(attachment,key);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAttachment_SetStringValue(FPDF_ATTACHMENT attachment,FPDF_BYTESTRING key,FPDF_WIDESTRING value){
return FPDFAttachment_SetStringValue(attachment,key,value);
}
FFI_PLUGIN_EXPORT unsigned long PDFIUM_FPDFAttachment_GetStringValue(FPDF_ATTACHMENT attachment,FPDF_BYTESTRING key,FPDF_WCHAR * buffer,unsigned long buflen){
return FPDFAttachment_GetStringValue(attachment,key,buffer,buflen);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAttachment_SetFile(FPDF_ATTACHMENT attachment,FPDF_DOCUMENT document,const void * contents,unsigned long len){
return FPDFAttachment_SetFile(attachment,document,contents,len);
}
FFI_PLUGIN_EXPORT FPDF_BOOL PDFIUM_FPDFAttachment_GetFile(FPDF_ATTACHMENT attachment,void * buffer,unsigned long buflen,unsigned long * out_buflen){
return FPDFAttachment_GetFile(attachment,buffer,buflen,out_buflen);
}
