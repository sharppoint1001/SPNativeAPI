#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "spapidll.h"
#include   <time.h> 



/*請求回復函數*/
/*隙葩滲杅*/
void SPDLLCALL LoginReply(long ret_code, char *ret_msg);  							   //腎翹隙葩 //登錄回復
void SPDLLCALL ApiOrderRequestFailed(tinyint action, SPApiOrder *order, long err_code, char *err_msg);   //隆等渣昫隙覃 //請求訂單錯誤回調 //xiaolin 2012-12-20 add
void SPDLLCALL OrderReport(long rec_no, SPApiOrder *order);								   //隆等惆豢隙覃//訂單報告回調 //xiaolin 2012-12-20 add
void SPDLLCALL TradeReport(long rec_no, SPApiTrade *trade);								   //傖蝠惆豢隙覃//成交報告回調//xiaolin 2012-12-20 add
void SPDLLCALL ApiPriceUpdate(SPApiPrice *price);										   //歎跡載陔隙葩 //價格更新回復	
void SPDLLCALL LogoutReply(long ret_code, char *ret_msg);                                  //腎堤隙葩 //登出回復
void SPDLLCALL LoginStatusUpdate(long ret_status);										   //腎翹袨怓隙葩 //登錄狀態回復
void SPDLLCALL AccInfoReply(char *acc_no, int max_bal, int max_pos, int max_order);        //腎翹傖髡隙葩蚚誧陓洘 //登錄成功回復用戶信息
void SPDLLCALL TickerUpdate(SPApiTicker *ticker);										   //庈部傖蝠暮翹隙葩 //市場成交記錄回復
void SPDLLCALL PServerLinkStatusUpdate(short host_id, long con_status);					   //歎跡訧捅蟀諉袨怓隙葩 //價格資訊連接狀態回復
void SPDLLCALL ConnectionErrorUpdate(short host_id, long link_err);						   //蟀諉楷汜渣昫隙葩 //連接發生錯誤回復
void SPDLLCALL InstrumentListReply(bool is_ready, char *ret_msg);							//莉炵蹈樓婥隙葩//產品系列加載回復
void SPDLLCALL ProductListReply(bool is_ready, char *ret_msg);								//莉磁埮樓婥隙葩//產品合約加載回復
void SPDLLCALL PswChangeReply(long ret_code, char *ret_msg);								//党蜊躇鎢隙葩//修改密碼回復
void SPDLLCALL ProductListByCodeReply(char *inst_code, bool is_ready, char *ret_msg);

/*用戶自定方法*/
void AddOrder();									//狟等 //下單
void ChangeOrder();									//蜊等 //改單	//modif xiaolin 2012-12-24	   
void DeleteOrder();									//雪等 //撤單
void SetOrderInactive();							//扢离隆等汜虴迵拸虴 //設置訂單生效與無效   //modif xiaolin 2012-12-21
void GetOrder();									//馱釬笢腔垀衄隆等 //取工作中的所有訂單
void OrderCount();									//眒樓婥腔隆等杅講 //取已加載的訂單數量

void PosCount();									 //脤戙厥累杅講 //查詢持倉數量
void GetPos();										 //脤戙厥累 //查詢持倉
void GetPosByProduct();								 //脤戙硌隅磁埮厥累 //查詢指定合約持倉

void TradeCount();									 //脤戙傖蝠暮翹杅講 //查詢成交記錄數量
void GetTrade();									 //脤戙傖蝠暮翹 //查詢成交記錄
void GetTradeByProduct();							 //跦擂硌尨ID迵傖蝠ID 脤戙傖蝠暮翹 //根據指示ID與成交ID 查詢成交記錄

void SubscribeUninitPrice(int idx);					 //隅砱迵庋溫磁埮 idx=1 隅砱ㄛidx=0 庋溫 //定義與釋放合約 idx=1 定義，idx=0 釋放
void GetPriceCount();								 //隅砱磁埮腔杅講 //定義合約的數量
void GetPrice();								     //隅砱磁埮腔陓洘 //取定義合約的信息
void GetPriceByCode();							     //跦擂磁埮眈茼磁埮腔陓洘 //根據合約取相應合約的信息取合約列表。
void GetInstrument();								 //脤戙莉炵蹈腔杅講迵垀衄腔莉炵蹈 //查詢產品系列的數量與所有的產品系列
void GetInstrumentByCode();							 //跦擂莉炵蹈測鎢脤戙莉炵蹈腔陓洘 //根據產品系列代碼查詢產品系列的信息
void GetProduct();									 //脤戙垀衄莉腔杅講迵垀衄腔莉陓洘 //查詢所有產品的數量與所有的產品信息
void GetProductByCode();							 //跦擂莉腔磁埮測鎢脤戙莉陓洘 //根據產品的合約代碼查詢產品信息

void LoadInstrumentList();							//樓婥庈部莉炵蹈陓洘//加載市場產品系列信息
void LoadProductInfoList();							//樓婥庈部莉磁埮陓洘//加載市場產品合約信息
void LoadProductInfoListByCode();

void SubscribeTicker();								 //脤艘庈部傖蝠暮翹 //查看市場成交記錄    
void UninitTicker();								 //迠婥庈部傖蝠暮翹 //卸載市場成交記錄

void HelpInfo();
void HelpOrder();
void HelpPos();
void HelpTrade();
void HelpPrice();
void HelpTicker();
void HelpCash();
void getTime(TCHAR *chBuf);
char *UserStatus(long status_id);
char *OutputOrderStatus(char status);

void Login();						//腎翹 //登錄
void Logout();						//腎堤 //登出
void GetAccInfo();					//脤戙蚚誧梖誧陓洘 //查詢用戶賬戶信息
void GetAccBalCount();				//脤戙蚚誧珋踢賦豻杅講 //查詢用戶現金結餘數量
void GetAccBal();					//脤戙珋踢賦豻 //查詢現金結餘
void GetAccBalByCurrency();			//脤戙硌隅珋踢賦豻//查詢指定現金結餘
void GetConnectionStatus();			//脤戙蚚誧蟀諉袨怓 //查詢用戶連接狀態

void getTime1(TCHAR *chBuf);
void getTime2(TCHAR *chBuf);
long EncodeDateTimeSerial(u_short year, u_short month, u_short day, u_short hour, u_short min, u_short sec);

//add xiaolin 2012-12-20
void LoadOrderReport();				//樓婥隆等//加載訂單
void LoadTradeReport();				//樓婥傖蝠暮翹//加載成交記錄

void ChangePassword();				//党蜊蚚誧躇鎢//修改用戶密碼

/*用戶自定變量*/
/*蚚誧赻隅曹講*/
const int nBufSize = 256;
char host[256],user_id[256],password[256],acc_no[16], license[256], app_id[16];
bool login_status = false;			//腎翹袨怓梓暮 //登錄狀態標記
int  port;							//腎翹傷諳 //登錄端口

TCHAR T1[nBufSize];
TCHAR T2[nBufSize];
int s1, ms1;
int s2, ms2;
int ATotal=0;
int ACount=1;
int AUpated=0;


/*Register define*/
p_SPAPI_RegisterLoginReply				 SPAPI_RegisterLoginReply;
p_SPAPI_RegisterLogoutReply				 SPAPI_RegisterLogoutReply; 
p_SPAPI_RegisterLoginStatusUpdate        SPAPI_RegisterLoginStatusUpdate;
p_SPAPI_RegisterOrderRequestFailed		 SPAPI_RegisterOrderRequestFailed;  //xiaolin 2012-12-20 add
p_SPAPI_RegisterApiPriceUpdate		     SPAPI_RegisterApiPriceUpdate;
p_SPAPI_RegisterLoginAccInfo		     SPAPI_RegisterLoginAccInfo;
p_SPAPI_RegisterTickerUpdate			 SPAPI_RegisterTickerUpdate;
p_SPAPI_RegisterPServerLinkStatusUpdate  SPAPI_RegisterPServerLinkStatusUpdate;
p_SPAPI_RegisterConnectionErrorUpdate    SPAPI_RegisterConnectionErrorUpdate;
p_SPAPI_RegisterOrderReport			     SPAPI_RegisterOrderReport;//xiaolin 2012-12-20 add
p_SPAPI_RegisterTradeReport				 SPAPI_RegisterTradeReport;//xiaolin 2012-12-20 add
p_SPAPI_RegisterProductListReply         SPAPI_RegisterProductListReply;
p_SPAPI_RegisterInstrumentListReply      SPAPI_RegisterInstrumentListReply;
p_SPAPI_RegisterPswChangeReply           SPAPI_RegisterPswChangeReply;
p_SPAPI_RegisterProductListByCodeReply   SPAPI_RegisterProductListByCodeReply;

/*初始化,poll,登錄登出 定義*/
/*場宎趙,poll,腎翹腎堤 隅砱*/
p_SPAPI_Initialize		   SPAPI_Initialize;			//場宎趙 //初始化
p_SPAPI_Uninitialize	   SPAPI_Uninitialize;			//庋溫 //釋放
p_SPAPI_Poll			   SPAPI_Poll;					//膘蕾珨沭籵陓蟀諉ㄛ蛁:場宎趙綴腎翹拸癹悜遠 //建立一條通信連接，注:初始化後登錄前無限循環請求
p_SPAPI_SetBackgroundPoll  SPAPI_SetBackgroundPoll;		//膘蕾珨沭陔腔盄最蟀諉ㄛ硐剒珨棒ㄛ膘祜蚚 SPAPI_Poll. //建立一條新的線程連接，只需請求一次，建議用 SPAPI_Poll.
p_SPAPI_SetLoginInfo	   SPAPI_SetLoginInfo;			//楷冞腎翹陓洘ㄛ翋儂 傷諳 蚚誧靡 躇鎢脹 //發送登錄信息，主機 端口 用戶名 密碼等
p_SPAPI_Login			   SPAPI_Login;					//腎翹 //登錄
p_SPAPI_Logout			   SPAPI_Logout;				//腎堤 //登出

/*買賣指示方法定義*/
/*鎗闖硌尨源楊隅砱*/
p_SPAPI_AddOrder		   SPAPI_AddOrder;				//狟等 //下單
p_SPAPI_ChangeOrder		   SPAPI_ChangeOrder;			//蜊等 //改單
p_SPAPI_DeleteOrder		   SPAPI_DeleteOrder;		    //雪等 //撤單
p_SPAPI_InactivateOrder    SPAPI_InactivateOrder;       //扢离拸虴隆等//設置無效訂單 xiaolin 2012-12-20 add
p_SPAPI_ActivateOrder      SPAPI_ActivateOrder;         //扢离衄虴隆等//設置有效訂單 xiaolin 2012-12-20 add
p_SPAPI_GetOrderCount	   SPAPI_GetOrderCount;			//脤戙鎗闖硌尨杅講 //查詢買賣指示數量
p_SPAPI_GetOrder		   SPAPI_GetOrder;				//脤戙鎗闖硌尨 //查詢買賣指示 
p_SPAPI_GetOrderByOrderNo  SPAPI_GetOrderByOrderNo;		//跦擂鎗闖硌尨ID脤戙眈茼陓洘 //根據買賣指示ID查詢相應信息

/*持倉方法定義*/
/*厥累源楊隅砱*/
p_SPAPI_GetPosCount		   SPAPI_GetPosCount;			//脤戙厥累杅講 //查詢持倉數量
p_SPAPI_GetPos			   SPAPI_GetPos;				//脤戙厥累陓洘 //查詢持倉信息
p_SPAPI_GetPosByProduct    SPAPI_GetPosByProduct;		//跦擂磁埮脤戙厥累陓洘 //根據合約查詢持倉信息

/*成交記錄方法定義*/
/*傖蝠暮翹源楊隅砱*/
p_SPAPI_GetTradeCount      SPAPI_GetTradeCount;			//脤戙傖蝠杅講 //查詢成交數量
p_SPAPI_GetTrade           SPAPI_GetTrade;				//脤戙傖蝠暮翹陓洘 //查詢成交記錄信息
p_SPAPI_GetTradeByTradeNo  SPAPI_GetTradeByTradeNo;		//跦擂鎗闖硌尨ID迵傖蝠ID脤戙傖蝠陓洘 //根據買賣指示ID與成交ID查詢成交信息

/*狀態方法定義*/
/*袨怓源楊隅砱*/
p_SPAPI_GetLoginStatus     SPAPI_GetLoginStatus;		//脤戙絞腎翹袨怓 //查詢當前登錄狀態

/*取價方法定義*/
/*歎源楊隅砱*/
p_SPAPI_SubscribePrice     SPAPI_SubscribePrice;		//隅砱磁埮歎跡 //定義合約價格
p_SPAPI_GetPriceCount      SPAPI_GetPriceCount;			//絞隅隅砱賸腔磁埮杅講 //取當定定義了的合約數量
p_SPAPI_GetPrice           SPAPI_GetPrice;				//脤戙磁埮陓洘 //查詢合約信息
p_SPAPI_GetPriceByCode	   SPAPI_GetPriceByCode;		//跦擂磁埮脤戙磁埮陓洘 //根據合約查詢合約信息
p_SPAPI_GetInstrumentCount SPAPI_GetInstrumentCount;    //脤戙莉炵蹈杅講 //查詢產品系列數量
p_SPAPI_GetInstrument      SPAPI_GetInstrument;			//跦擂齬唗脤戙垀衄莉炵蹈陓洘 //根據排序查詢所有產品系列信息
p_SPAPI_GetInstrumentByCode  SPAPI_GetInstrumentByCode; //跦擂莉炵蹈測鎢脤戙莉炵蹈腔陓洘 //根據產品系列代碼查詢產品系列的信息
p_SPAPI_GetProductCount      SPAPI_GetProductCount;		//脤戙垀衄莉腔杅講 //查詢所有產品的數量
p_SPAPI_GetProduct           SPAPI_GetProduct;			//跦擂齬唗脤戙垀衄莉腔陓洘 //根據排序查詢所有產品的信息
p_SPAPI_GetProductByCode     SPAPI_GetProductByCode;	//跦擂莉腔磁埮測鎢脤戙莉腔陓洘 //根據產品的合約代碼查詢產品的信息
p_SPAPI_LoadProductInfoListByCode SPAPI_LoadProductInfoListByCode;

/*市場成交記錄*/
/*庈部傖蝠暮翹*/
p_SPAPI_SubscribeTicker    SPAPI_SubscribeTicker;		//庈部傖蝠暮翹 //市場成交記錄

/*戶口資料*/
/*誧諳訧蹋*/
p_SPAPI_GetAccInfo           SPAPI_GetAccInfo;			//脤戙誧諳訧蹋 // 查詢戶口資料
p_SPAPI_GetAccBalCount       SPAPI_GetAccBalCount;		//脤戙珋踢賦豻腔跺杅 // 查詢現金結餘的個數
p_SPAPI_GetAccBal            SPAPI_GetAccBal;			//脤戙珋踢賦豻陓洘 // 查詢現金結餘信息
p_SPAPI_GetAccBalByCurrency  SPAPI_GetAccBalByCurrency; //跦擂億啟脤戙珋踢賦豻 // 根據貨幣查詢現金結餘

/*DLL版本*/
/*DLL唳掛*/
p_SPAPI_GetDllVersion        SPAPI_GetDllVersion;		//脤戙DLL唳掛 楷票唳掛 楷票奀潔 //查詢DLL版本 發佈版本 發佈時間
p_SPAPI_GetDLLVersion        SPAPI_GetDLLVersionDouble; //脤戙DLL唳掛 //查詢DLL版本 xiaolin 2012-12-21 add

/*樓婥隆等迵傖蝠暮翹*/
p_SPAPI_LoadOrderReport SPAPI_LoadOrderReport;			//樓婥掛棒腎翹腔馱釬笢隆等陓洘,蜆源楊硐菴珨棒奀衄虴.//加載本次登錄前的工作中訂單信息,該方法只請求第一次時有效.
p_SPAPI_LoadTradeReport SPAPI_LoadTradeReport;			//樓婥掛棒腎翹腔傖蝠暮翹陓洘,蜆源楊硐菴珨棒奀衄虴.  //加載本次登錄前的成交記錄信息,該方法只請求第一次時有效.

p_SPAPI_LoadInstrumentList  SPAPI_LoadInstrumentList;	//樓婥庈部窒莉炵蹈陓洘
p_SPAPI_LoadProductInfoList SPAPI_LoadProductInfoList;	//樓婥庈部窒莉磁埮陓洘

p_SPAPI_ChangePassword      SPAPI_ChangePassword;		//党蜊蚚誧躇鎢

int main(void)
{
int ord_req_no = 1;
int ch;

	/*Initi start*/
     HINSTANCE hInst = LoadLibrary("spapidll.dll");
     SPAPI_Initialize = (p_SPAPI_Initialize)GetProcAddress(hInst, "SPAPI_Initialize");
	 int result = SPAPI_Initialize();
     printf("\nInitialize Result %s", (result == 0)?"Succeed":"Fail");
	 if(result == 0){

		/*register callback start*/
		SPAPI_RegisterOrderRequestFailed = (p_SPAPI_RegisterOrderRequestFailed)GetProcAddress(hInst, "SPAPI_RegisterOrderRequestFailed");
		SPAPI_RegisterOrderRequestFailed(ApiOrderRequestFailed);

		SPAPI_RegisterLoginReply = (p_SPAPI_RegisterLoginReply)GetProcAddress(hInst, "SPAPI_RegisterLoginReply");
		SPAPI_RegisterLoginReply(LoginReply);

		//xiaolin 2012-12-20 add OrderReport TradeReport
		SPAPI_RegisterOrderReport = (p_SPAPI_RegisterOrderReport)GetProcAddress(hInst, "SPAPI_RegisterOrderReport");
		SPAPI_RegisterOrderReport(OrderReport);
		SPAPI_RegisterTradeReport = (p_SPAPI_RegisterTradeReport)GetProcAddress(hInst, "SPAPI_RegisterTradeReport");
		SPAPI_RegisterTradeReport(TradeReport);
		
		SPAPI_RegisterApiPriceUpdate = (p_SPAPI_RegisterApiPriceUpdate)GetProcAddress(hInst, "SPAPI_RegisterApiPriceUpdate");
		SPAPI_RegisterApiPriceUpdate(ApiPriceUpdate);
		
		SPAPI_RegisterLogoutReply = (p_SPAPI_RegisterLogoutReply)GetProcAddress(hInst, "SPAPI_RegisterLogoutReply");
        SPAPI_RegisterLogoutReply(LogoutReply);

        SPAPI_RegisterLoginStatusUpdate = (p_SPAPI_RegisterLoginStatusUpdate)GetProcAddress(hInst, "SPAPI_RegisterLoginStatusUpdate");
        SPAPI_RegisterLoginStatusUpdate(LoginStatusUpdate);

		SPAPI_RegisterLoginAccInfo = (p_SPAPI_RegisterLoginAccInfo)GetProcAddress(hInst, "SPAPI_RegisterLoginAccInfo");
        SPAPI_RegisterLoginAccInfo(AccInfoReply);

		SPAPI_RegisterTickerUpdate = (p_SPAPI_RegisterTickerUpdate)GetProcAddress(hInst, "SPAPI_RegisterTickerUpdate");
		SPAPI_RegisterTickerUpdate(TickerUpdate);


		SPAPI_RegisterPServerLinkStatusUpdate = (p_SPAPI_RegisterPServerLinkStatusUpdate)GetProcAddress(hInst, "SPAPI_RegisterPServerLinkStatusUpdate");
		SPAPI_RegisterPServerLinkStatusUpdate(PServerLinkStatusUpdate);
		
		SPAPI_RegisterConnectionErrorUpdate = (p_SPAPI_RegisterConnectionErrorUpdate)GetProcAddress(hInst, "SPAPI_RegisterConnectionErrorUpdate");
		SPAPI_RegisterConnectionErrorUpdate(ConnectionErrorUpdate);

		SPAPI_RegisterProductListReply = (p_SPAPI_RegisterProductListReply)GetProcAddress(hInst, "SPAPI_RegisterProductListReply");
		SPAPI_RegisterProductListReply(ProductListReply);

		SPAPI_RegisterInstrumentListReply = (p_SPAPI_RegisterInstrumentListReply)GetProcAddress(hInst, "SPAPI_RegisterInstrumentListReply");
		SPAPI_RegisterInstrumentListReply(InstrumentListReply);

		SPAPI_RegisterPswChangeReply = (p_SPAPI_RegisterPswChangeReply)GetProcAddress(hInst, "SPAPI_RegisterPswChangeReply");
		SPAPI_RegisterPswChangeReply(PswChangeReply);

		SPAPI_RegisterProductListByCodeReply = (p_SPAPI_RegisterProductListByCodeReply)GetProcAddress(hInst, "SPAPI_RegisterProductListByCodeReply");
		SPAPI_RegisterProductListByCodeReply(ProductListByCodeReply);

		/*polling,login start*/
		SPAPI_Poll = (p_SPAPI_Poll)GetProcAddress(hInst, "SPAPI_Poll");
		SPAPI_SetBackgroundPoll =(p_SPAPI_SetBackgroundPoll)GetProcAddress(hInst, "SPAPI_SetBackgroundPoll");
		SPAPI_SetLoginInfo = (p_SPAPI_SetLoginInfo)GetProcAddress(hInst, "SPAPI_SetLoginInfo");
		SPAPI_Login = (p_SPAPI_Login)GetProcAddress(hInst, "SPAPI_Login");
		SPAPI_Logout = (p_SPAPI_Logout)GetProcAddress(hInst, "SPAPI_Logout");

		/*Info start*/
		SPAPI_GetAccInfo = (p_SPAPI_GetAccInfo)GetProcAddress(hInst, "SPAPI_GetAccInfo");
		SPAPI_GetAccBalCount = (p_SPAPI_GetAccBalCount)GetProcAddress(hInst, "SPAPI_GetAccBalCount");   
		SPAPI_GetAccBal = (p_SPAPI_GetAccBal)GetProcAddress(hInst, "SPAPI_GetAccBal");         
		SPAPI_GetAccBalByCurrency = (p_SPAPI_GetAccBalByCurrency)GetProcAddress(hInst, "SPAPI_GetAccBalByCurrency"); 

		SPAPI_GetDllVersion = (p_SPAPI_GetDllVersion)GetProcAddress(hInst, "SPAPI_GetDllVersion");
		SPAPI_GetDLLVersionDouble = (p_SPAPI_GetDLLVersion)GetProcAddress(hInst, "SPAPI_GetDLLVersion");
		
		/*Order start*/
		SPAPI_AddOrder = (p_SPAPI_AddOrder)GetProcAddress(hInst, "SPAPI_AddOrder");
		SPAPI_ChangeOrder = (p_SPAPI_ChangeOrder)GetProcAddress(hInst, "SPAPI_ChangeOrder");
		SPAPI_DeleteOrder = (p_SPAPI_DeleteOrder)GetProcAddress(hInst, "SPAPI_DeleteOrder");
		SPAPI_InactivateOrder  =  (p_SPAPI_InactivateOrder)GetProcAddress(hInst, "SPAPI_InactivateOrder");
		SPAPI_ActivateOrder  =  (p_SPAPI_ActivateOrder)GetProcAddress(hInst, "SPAPI_ActivateOrder");
		SPAPI_GetOrderCount = (p_SPAPI_GetOrderCount)GetProcAddress(hInst, "SPAPI_GetOrderCount");
		SPAPI_GetOrder = (p_SPAPI_GetOrder)GetProcAddress(hInst, "SPAPI_GetOrder");
		SPAPI_GetOrderByOrderNo = (p_SPAPI_GetOrderByOrderNo)GetProcAddress(hInst, "SPAPI_GetOrderByOrderNo");


		/*Position start*/
		SPAPI_GetPosCount = (p_SPAPI_GetPosCount)GetProcAddress(hInst, "SPAPI_GetPosCount");
		SPAPI_GetPos = (p_SPAPI_GetPos)GetProcAddress(hInst, "SPAPI_GetPos");
		SPAPI_GetPosByProduct = (p_SPAPI_GetPosByProduct)GetProcAddress(hInst, "SPAPI_GetPosByProduct");

		/*Trade start*/
		SPAPI_GetTradeCount = (p_SPAPI_GetTradeCount)GetProcAddress(hInst, "SPAPI_GetTradeCount");
		SPAPI_GetTrade = (p_SPAPI_GetTrade)GetProcAddress(hInst, "SPAPI_GetTrade");
		SPAPI_GetTradeByTradeNo = (p_SPAPI_GetTradeByTradeNo)GetProcAddress(hInst, "SPAPI_GetTradeByTradeNo");

		/*Status start*/
		SPAPI_GetLoginStatus = (p_SPAPI_GetLoginStatus)GetProcAddress(hInst, "SPAPI_GetLoginStatus");		
				
		/*Pricing start*/
		SPAPI_SubscribePrice = (p_SPAPI_SubscribePrice)GetProcAddress(hInst, "SPAPI_SubscribePrice");
		SPAPI_GetPriceCount = (p_SPAPI_GetPriceCount)GetProcAddress(hInst, "SPAPI_GetPriceCount");
		SPAPI_GetPrice = (p_SPAPI_GetPrice)GetProcAddress(hInst, "SPAPI_GetPrice");
		SPAPI_GetPriceByCode = (p_SPAPI_GetPriceByCode)GetProcAddress(hInst, "SPAPI_GetPriceByCode");
	
		SPAPI_GetInstrumentCount = (p_SPAPI_GetInstrumentCount)GetProcAddress(hInst, "SPAPI_GetInstrumentCount");
		SPAPI_GetInstrument = (p_SPAPI_GetInstrument)GetProcAddress(hInst, "SPAPI_GetInstrument");
		SPAPI_GetInstrumentByCode = (p_SPAPI_GetInstrumentByCode)GetProcAddress(hInst, "SPAPI_GetInstrumentByCode");
		SPAPI_GetProductCount  = (p_SPAPI_GetProductCount)GetProcAddress(hInst, "SPAPI_GetProductCount");
		SPAPI_GetProduct  = (p_SPAPI_GetProduct)GetProcAddress(hInst, "SPAPI_GetProduct");
		SPAPI_GetProductByCode  = (p_SPAPI_GetProductByCode)GetProcAddress(hInst, "SPAPI_GetProductByCode");

		/*Ticker start*/
		SPAPI_SubscribeTicker = (p_SPAPI_SubscribeTicker)GetProcAddress(hInst, "SPAPI_SubscribeTicker");

		SPAPI_LoadOrderReport = (p_SPAPI_LoadOrderReport)GetProcAddress(hInst, "SPAPI_LoadOrderReport");
		SPAPI_LoadTradeReport = (p_SPAPI_LoadTradeReport)GetProcAddress(hInst, "SPAPI_LoadTradeReport");
		
		SPAPI_LoadInstrumentList  = (p_SPAPI_LoadInstrumentList)GetProcAddress(hInst, "SPAPI_LoadInstrumentList");
		SPAPI_LoadProductInfoList = (p_SPAPI_LoadProductInfoList)GetProcAddress(hInst, "SPAPI_LoadProductInfoList");
		SPAPI_LoadProductInfoListByCode =(p_SPAPI_LoadProductInfoListByCode)GetProcAddress(hInst, "SPAPI_LoadProductInfoListByCode");
			  
		SPAPI_ChangePassword = (p_SPAPI_ChangePassword)GetProcAddress(hInst, "SPAPI_ChangePassword");

		//SPAPI_Poll();
		HelpInfo();
		SPAPI_SetBackgroundPoll(1);    //用DLL方法之前必須調用SPAPI_SetBackgroundPoll或循環調用SPAPI_Poll
									   //蚚DLL源楊眳斛剕覃蚚SPAPI_SetBackgroundPoll麼悜遠覃蚚SPAPI_Poll

		Login();
		while(1){
			if(kbhit())	{
				ch = getch();
				if(ch == 49) HelpOrder();                        //Num 1
				if(ch == 50) HelpPos();                          //Num 2
				if(ch == 51) HelpTrade();						 //Num 3
				if(ch == 52) HelpCash();						 //Num 4
				if(ch == 53) HelpPrice();						 //Num 5
				if(ch == 54) HelpTicker();                       //Num 6
				if(ch == 55) Login();		                     //Num 7
				if(ch == 56) Logout();					         //Num 8
				if(ch == 57) HelpInfo();						 //Num 9
				
				if(!login_status) continue;
				if(ch == 103) AddOrder();						  //g
				if(ch == 102) DeleteOrder();					  //f
				if(ch == 100) ChangeOrder();                      //d
				if(ch == 115) LoadOrderReport();                  //s
				if(ch == 97)  GetOrder();					      //a
				if(ch == 120) SetOrderInactive();                 //x
				if(ch == 113)  OrderCount();                      //q

				if(ch == 104) PosCount();                          //h
				if(ch == 106) GetPos();							   //j
				if(ch == 107) GetPosByProduct();				   //k

				if(ch == 116) TradeCount();						   //t
				if(ch == 114) GetTrade();						   //r
				if(ch == 101) GetTradeByProduct();				   //e
				if(ch == 119) LoadTradeReport();				   //w

				if(ch == 121) SubscribeUninitPrice(1);				//y
				if(ch == 117) GetPriceCount();						//u
				if(ch == 105) GetPrice();							//i
				if(ch == 111) GetPriceByCode();						//o
				if(ch == 112) SubscribeUninitPrice(0);              //p
				if(ch == 91)  LoadInstrumentList();					//[
				if(ch == 93)  GetInstrument();						//]
				if(ch == 92)  GetInstrumentByCode();				//'\'
				if(ch == 108) LoadProductInfoList();				//l
				if(ch == 59)  GetProduct();							//;
				if(ch == 39)  GetProductByCode();					//'

				if(ch == 110) GetAccInfo();							//n
				if(ch == 98)  GetAccBalCount();                     //b
				if(ch == 118) GetAccBal();							//v   
				if(ch == 99)  GetAccBalByCurrency();				//c
				if(ch == 122) GetConnectionStatus();				//z

				if(ch == 44)  SubscribeTicker();                    //,
				if(ch == 46)  UninitTicker();                       //.
				if(ch == 48)  ChangePassword();						//0
				if(ch == 45)  LoadProductInfoListByCode();							//-
				if(ch == 61)  ;					//=
				
			}
			Sleep(1);
		}
	 }
     FreeLibrary(hInst);
     return 0;
 
}

#pragma region 奀潔源楊  時間方法
void getTime(TCHAR *chBuf) 
{
SYSTEMTIME stLocal;
GetLocalTime(&stLocal);

	sprintf(chBuf, "Time: %u/%u/%u %u:%u:%u:%u",                 
	stLocal.wYear, stLocal.wMonth, stLocal.wDay,
	stLocal.wHour, stLocal.wMinute, stLocal.wSecond,
	stLocal.wMilliseconds);
}

void getTime1(TCHAR *chBuf) 
{
SYSTEMTIME stLocal;
GetLocalTime(&stLocal);

	sprintf(chBuf, "Time: %u/%u/%u %u:%u:%u:%u",                 
	stLocal.wYear, stLocal.wMonth, stLocal.wDay,
	stLocal.wHour, stLocal.wMinute, stLocal.wSecond,
	stLocal.wMilliseconds);

	s1 = stLocal.wSecond;
	ms1 = stLocal.wMilliseconds;
}

void getTime2(TCHAR *chBuf) 
{
SYSTEMTIME stLocal;
GetLocalTime(&stLocal);

	sprintf(chBuf, "Time: %u/%u/%u %u:%u:%u:%u",                 
	stLocal.wYear, stLocal.wMonth, stLocal.wDay,
	stLocal.wHour, stLocal.wMinute, stLocal.wSecond,
	stLocal.wMilliseconds);

	s2 = stLocal.wSecond;
	ms2 = stLocal.wMilliseconds;
}
#pragma endregion

#pragma region Order鎗闖硌尨  買賣指示


void AddOrder()
{
SPApiOrder ord;
int rc, cond, t;
int dec_price;
TCHAR chBuf[nBufSize];
double stop, toler, step, level, profit, loss, loss_tol;

int pc, mkt_price;
SPApiPrice price;
double mkt_toler;
mkt_price = 0;

	memset(&ord, 0, sizeof(ord));
	memset(&price, 0, sizeof(price));
	printf("\n|----------Input Add Order Cond----------|");
	printf("\n|   1:Normal,         2:Enhanced Stop,   |");
	printf("\n|   3:OCO,            4:Bull & Bear,     |");
	printf("\n|   5:Time to Send,   6:Open&Close(Today)|");
	printf("\n|----------------------------------------|");
	scanf("%d",&cond);
	if (cond < 1 || cond > 6)
	{
		printf("\n>>>>>>>>>>Input Add Order Cond Error!");
		return;
	}
	strcpy(ord.AccNo, acc_no);
    strcpy(ord.Initiator, user_id);
	strcpy(ord.Ref,"@TRADERAPI_VC");
    strcpy(ord.Ref2,"");
    strcpy(ord.GatewayCode,"");
	ord.ValidType = 0;
	ord.CondType = 0;
	ord.OpenClose = OC_DEFAULT;
	
	printf("\n>>>>>>>>Input Order ProdCode: ");	        scanf("%s",&ord.ProdCode);getchar();
	//printf("\n>>>>>>>>Input ProdCode DecInPrice: ");    scanf("%d",&dec_price);
	printf("\n>>>>>>>>Set T+1 (1:Yes,0:No)");			scanf("%d",&t);
	printf("\n>>>>>>>>Input ClOrderId:");	            scanf("%s",&ord.ClOrderId);
	ord.DecInPrice = 0;
	if(t == 1) ord.OrderOptions = 1;
	/*一般*//*珨啜*/
	if(cond == 1)
	{
		ord.CondType = 0;
		int price_flag,validity_type;
		printf("\n>>>>>>>>Price Type(0:Limit,1:AO,2:Market Price): ");	scanf("%d",&price_flag);
		if(price_flag == 0)
		{
			printf("\n>>>>>>>>Input Order Price: ");					scanf("%lf",&ord.Price);
			ord.OrderType = ORD_LIMIT;
		}
		if(price_flag == 1)
		{
			/*AO_PRC =噥歎  競價*/
			ord.Price = AO_PRC;
			ord.OrderType = ORD_AUCTION;
			ord.StopType = 0;
			ord.StopLevel = 0;
		}
		if(price_flag == 2)
		{
			/*庈歎等 市價單*/
			ord.Price = 0;
			ord.OrderType = ORD_MARKET;
			ord.StopType = 0;
			ord.StopLevel = 0;
		}

		if(price_flag == 0)
		{
			/*隆等衄虴笱濬 訂單有效期種類*/
			printf("\n>>>>>>>>Input Validity Type(0:ToDay,1:FaK,2:FoK,3:GTC,4:GTD): ");	  scanf("%d",&validity_type);
			ord.ValidType = validity_type;
			if (validity_type == 4)
			{	
				/*4:GTD 硌隅隆等  指定日期訂單*/
				int year,month,day;
				printf("\n>>>>>>>>Input Date(form:yy-mm-dd): ");  scanf("%d-%d-%d",&year,&month,&day);
				ord.ValidTime = EncodeDateTimeSerial(year,month,day,23,59,59);
			}

			if (validity_type == 0 || validity_type == 3 || validity_type == 4 || validity_type == 2)
			{
				/*絞衄虴笱濬峈 0:ToDay,3:GTC,4:GTD奀,蚚誧褫扢离 砦囷/揖楷 歎跡*/
				/*當有效期種類為 0:ToDay,3:GTC,4:GTD時,用戶可設置 止損/觸發 價格*/
				int stop_trigger, flag;
				printf("\n>>>>>>>>Input Stop/Trigger Price(1:Yes,0:No): ");  scanf("%d",&flag);
				if(flag == 1)
				{
					ord.CondType = 1;
					/*砦囷迵揖楷歎跡腔笱濬,0:癹歎砦囷,1:汔庈揖楷,2:埲庈揖楷,3:庈部砦囷*/
					/*止損與觸發價格的種類,0:限價止損,1:升市觸發,2:躍市觸發,3:市場止損*/
					printf("\n>>>>>>>>Input Stop/Trigger Type(0:Stop Limit,1:UpTrigger,2:DownTrigger,3:Stop Market): ");  scanf("%d",&stop_trigger);
					if(stop_trigger == 0)ord.StopType = STOP_LOSS;
					if(stop_trigger == 1)ord.StopType = STOP_UP;
					if(stop_trigger == 2)ord.StopType = STOP_DOWN;
					if(stop_trigger == 3)
					{
						ord.Price = 0;
						ord.OrderType = ORD_MARKET;
						ord.StopType = STOP_LOSS;
					}
					printf("\n>>>>>>>>Input Stop Price:");  scanf("%lf",&ord.StopLevel);
				}
			}
			
		}
	    
		
	    printf("\n>>>>>>>>Input Order Qty: ");						scanf("%d",&ord.Qty);     getchar(); 
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);
	}

	/*增強止損*//*崝砦囷*/
	if (cond == 2)
	{
		ord.CondType = 6;
		printf("\n>>>>>>>>Input Order Market Price: ");	scanf("%lf",&ord.Price);
		printf("\n>>>>>>>>Input Order Level Price: ");	scanf("%lf",&level);
		printf("\n>>>>>>>>Input Order Toler: ");        scanf("%lf",&toler);
		printf("\n>>>>>>>>Input Order step: ");	        scanf("%lf",&step);
	    printf("\n>>>>>>>>Input Order Qty: ");	        scanf("%d",&ord.Qty);     getchar(); 		
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);

		ord.StopLevel = level;
	    ord.StopType = STOP_LOSS;

		if (ord.BuySell == 'B')
		{
			ord.UpLevel = ord.Price;
			ord.UpPrice = level;
			ord.Price = level + toler;
			ord.DownLevel = step;
		}
		else
		{
			ord.DownLevel = ord.Price;
			ord.DownPrice = level;
			ord.Price = level - toler;
			ord.UpLevel = step;
		}
	}


	/*雙向限價盤*//*邧砃癹歎攫*/
	if (cond == 3)
	{
		ord.CondType = 4;
	    printf("\n>>>>>>>>Input Order Price: ");	scanf("%lf",&ord.Price);
	    printf("\n>>>>>>>>Input Order Qty: ");	    scanf("%d",&ord.Qty);     getchar(); 
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);
		printf("\n>>>>>>>>Input Order Stop: ");	    scanf("%lf",&stop);
		printf("\n>>>>>>>>Input Order Toler: ");    scanf("%lf",&toler);
		if (ord.BuySell == 'B')
		{
			ord.UpLevel = stop;  
			ord.UpPrice = stop + toler;
		}
		else
		{
			ord.DownLevel = stop;  
			ord.DownPrice = stop - toler;
		}

	}

	/*牛市與熊市*//*籟庈迵倱庈*/
	if(cond == 4)
	{
		ord.CondType = 0;
	    printf("\n>>>>>>>>Input Order Price: ");	  scanf("%lf",&ord.Price);
		printf("\n>>>>>>>>Input Order Profit: ");	  scanf("%lf",&profit);
		printf("\n>>>>>>>>Input Order Loss: ");  	  scanf("%lf",&loss);
		printf("\n>>>>>>>>Input Order Loss Toler: "); scanf("%lf",&loss_tol);
	    printf("\n>>>>>>>>Input Order Qty: ");	      scanf("%d",&ord.Qty);     getchar(); 
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);

		if (ord.BuySell == 'B')
		{
			ord.UpLevel = ord.Price + profit;
			ord.UpPrice = ord.Price + profit;
			ord.DownLevel = ord.Price - loss;
			ord.DownPrice = ord.Price - loss - loss_tol;
		}
		else
		{
			ord.UpLevel = ord.Price - profit;
			ord.UpPrice = ord.Price - profit;
			ord.DownLevel = ord.Price + loss;
			ord.DownPrice = ord.Price + loss + loss_tol;
		}
	}

	/*啎隅奀潔楷冞*/
	if(cond == 5)
	{
		int year,month,day, hour, minute, second;
		printf("\n>>>>>>>>Input Date(form:yy-mm-dd): ");  scanf("%d-%d-%d",&year,&month,&day);
		printf("\n>>>>>>>>Input Time(form:HH:mm): ");  scanf("%d:%d:%d",&hour,&minute);
		ord.CondType = 3;
		ord.SchedTime = EncodeDateTimeSerial(year,month,day,hour,minute,0);
	    printf("\n>>>>>>>>Input Order Price: ");	      scanf("%lf",&ord.Price);
	    printf("\n>>>>>>>>Input Order Qty: ");			  scanf("%d",&ord.Qty);
		getchar(); 
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);
	}

	/*羲累累硌鍔 開倉平倉指令*/
	if(cond == 6)
	{
		int trigger,tri_type,cls_type,cond_type,step_idx;
		double profit, loss, loss_tol;
		double stop_loss, stop_loss_tol, trail_stop;
		int year,month,day, hour, minute, time_idx;

		 ord.OrderType = 0;
         ord.OpenClose = OC_DEFAULT;
         ord.CondType = COND_COMBO_OPEN;
         ord.ValidType = VLD_REST_OF_DAY;

		 printf("\n>>>>>>>>Input Open\n");
		 printf("\n>>>>>>>>Set Open Trigger (1:Yes,0:No): ");scanf("%d",&trigger);
		
		 if(trigger == 1)
		 {
			 /*羲累扢离揖楷濬倰 開倉設置觸發類型*/
			 printf("\n>>>>>>>>Input Open Trigger Type (1:UpTrigger,2:DownTrigger): ");scanf("%d",&tri_type);
			 if(tri_type == 1) ord.StopType = STOP_UP;
			 if(tri_type == 2) ord.StopType = STOP_DOWN;
			 printf("\n>>>>>>>>Input Stop Level Price: ");	scanf("%lf",&ord.StopLevel);
		 }
		 else
		 {
			 ord.StopType = 0;
			 ord.StopLevel = 0;
		 }
		 
		 printf("\n>>>>>>>>Input Order Price: ");	      scanf("%lf",&ord.Price);
	     printf("\n>>>>>>>>Input Order Qty: ");			  scanf("%d",&ord.Qty);

		 printf("\n>>>>>>>>Input Close\n");
		 printf("\n>>>>>>>>Input Close Type (0:OCO(points), 1:Stop(points), 2:OCO(prices), 3:Stop(prices).): ");scanf("%d",&cls_type);
		 /*累濬倰 平倉類型*/
		 if (cls_type == 0 || cls_type == 2)
		 {
				if(cls_type == 0) printf("\n>>>>>>>>Input Profit(points): ");
				else			  printf("\n>>>>>>>>Input Profit(prices): ");
								  scanf("%lf",&profit);

				if(cls_type == 0) printf("\n>>>>>>>>Input Loss(points): ");
				else			  printf("\n>>>>>>>>Input Loss(prices): ");
								  scanf("%lf",&loss);

				printf("\n>>>>>>>>Input Toler: ");scanf("%lf",&loss_tol);

				if(cls_type == 0) cond_type = COND_OCOSTOP;
				if(cls_type == 2) cond_type = COND_OCOSTOP_PRC;
				ord.UpLevel = cond_type;
                ord.UpPrice = profit;
                ord.DownLevel = loss;
                ord.DownPrice = loss_tol;			  
		 }
		 else if(cls_type == 1 || cls_type == 3)
		 {
			 if(cls_type == 1) printf("\n>>>>>>>>Input Profit(points): ");
			 else			   printf("\n>>>>>>>>Input Profit(prices): ");
							   scanf("%lf",&stop_loss);
			 printf("\n>>>>>>>>Input Toler: ");scanf("%lf",&stop_loss_tol);
			 printf("\n>>>>>>>>Input step(1:Yes,0:No): ");scanf("%d",&step_idx);
			 if (step_idx == 1)
			 {
				printf("\n>>>>>>>>Input Step: ");scanf("%lf",&trail_stop);
			 }
			 else
				 trail_stop = 0;

			 if(cls_type == 1) cond_type = (trail_stop==0)?COND_STOP:COND_TRAILSTOP;
			 if(cls_type == 3) cond_type = (trail_stop==0)?COND_STOP_PRC:COND_TRAILSTOP_PRC;
			 ord.UpLevel = cond_type;
             ord.UpPrice = trail_stop;
             ord.DownLevel = stop_loss;
             ord.DownPrice = stop_loss_tol;
		 }

		 if(trigger == 0 && (cls_type == 0 || cls_type == 1))
		 {
			 //庈歎 //市價
			 pc = SPAPI_GetPriceByCode(ord.ProdCode, &price);
			 if (pc == 0)
			 {
				 printf("\n>>>>>>>>Set Market Price(1:Yes,0:No): ");scanf("%d",&mkt_price);
				 if(mkt_price == 1)
				 {
					printf("\n>>>>>>>>Input Market Toler(DecInPrice:%d): ", price.DecInPrice);scanf("%lf",&mkt_toler);
				 }
			 }
		 }

		printf("\n>>>>>>>>Set Time to Close(1:Yes,0:No): ");scanf("%d",&time_idx);
		if(time_idx == 1)
		{
			/*啎埮奀潔累 預約時間平倉*/
			printf("\n>>>>>>>>Input Date(form:yy-mm-dd): ");  scanf("%d-%d-%d",&year,&month,&day);
			printf("\n>>>>>>>>Input Time(form:HH:mm): ");  scanf("%d:%d:%d",&hour,&minute);
			ord.SchedTime = EncodeDateTimeSerial(year,month,day,hour,minute,0);
		}
		
		getchar(); 
	    printf("\n>>>>>>>>Input Order Buy(B) or Sell(S): ");	    scanf("%c",&ord.BuySell);
		if (mkt_price == 1)
		{
			if (ord.BuySell == 'B')
				ord.Price = price.Ask[0] + mkt_toler;
			else
				ord.Price = price.Bid[0] + mkt_toler;
		}
	}

	for(int i=0;i<ACount;i++)
		rc = SPAPI_AddOrder(&ord);

	ATotal=0;
	AUpated=0;
	getTime1(chBuf);
	printf("\n\n[%s] Added Order.", chBuf);
	if(rc != 0) printf(" Error:%d", rc);
}

long EncodeDateTimeSerial(u_short year, u_short month, u_short day, u_short hour, u_short min, u_short sec)
{
struct tm tm;

    memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = min;
    tm.tm_sec = sec;
    return mktime(&tm);
}

//眒冪樓婥腔馱釬笢隆等杅講
void OrderCount()
{
int count;

	count = SPAPI_GetOrderCount();
	printf("\n Acc: %s,Order Count:%d", acc_no,count);
}

//馱釬笢腔垀衄隆等
void GetOrder()
{
	int cnt, i, rc;
	SPApiOrder order;

	cnt = SPAPI_GetOrderCount();
	for (i = 0; i < cnt; i++)
	{
		rc = SPAPI_GetOrder(i, &order);
		if (rc == 0)
		{
			printf("\n Order#=%u ,Status:%s, B/S = %c, ProdCode=%s, Price=%Lf, Qty=%ld, ClOrderId=%s", order.IntOrderNo, OutputOrderStatus(order.Status), order.BuySell, order.ProdCode, order.Price, order.Qty, order.ClOrderId);
		}
	}
	if (cnt == 0)
		printf("\n Acc: %s,Order Count:0", acc_no);
}

//扢离馱釬笢隆等腔衄虴迵拸虴
void SetOrderInactive()
{
long int_order_no, order_inactive;
int rc, oc;
SPApiOrder ord;
	
	printf("\n>>>>>>>>Input Int Order No: ");	scanf("%ld",&int_order_no);
	printf("\n>>>>>>>>Input 0=Activate, 1=Inactivate: ");	scanf("%ld",&order_inactive);
	
	oc = SPAPI_GetOrderByOrderNo(int_order_no, &ord);
	if (oc != 0)
	{
		printf("\n Acc: %s,No Order", acc_no);
		return;
	}
	
	if (order_inactive == 0)
		rc = SPAPI_ActivateOrder(&ord);	 //蔚隆等扢离峈衄虴隆等
	else if(order_inactive == 1)
		rc = SPAPI_InactivateOrder(&ord);//蔚隆等扢离峈拸虴隆等
	printf("\n rc: %d \n",rc);

}

//党蜊馱釬笢腔隆等
void ChangeOrder()
{
long int_order_no;
double org_price = 0;
double chg_price = 0;
SPApiOrder ord;
int rc, oc;

	memset(&ord, 0, sizeof(ord));
	printf("\n>>>>>>>>Input Int Order No: ");	scanf("%ld",&int_order_no);
	oc = SPAPI_GetOrderByOrderNo(int_order_no, &ord);
	if (oc == 0)
	{
		printf("\n>>>>>>>>Input org_price: ");		scanf("%lf",&org_price);
		printf("\n>>>>>>>>Input ClOrderId:");		scanf("%s",&ord.ClOrderId);
		chg_price = org_price;
		org_price = ord.Price;
		ord.Price = chg_price;
	

		rc = SPAPI_ChangeOrder(&ord, org_price, ord.Qty);
		printf("\n rc: %d \n",rc);
	}
	else
		printf("\n return oc: %d \n",oc);
}

//刉壺馱釬笢腔隆等
void DeleteOrder()
{
SPApiOrder ord;
int rc;
char prodcode[16];


	memset(&ord, 0, sizeof(ord));
	strcpy(ord.AccNo, acc_no);
	printf("\n>>>>>>>>Input Int Order No: ");	
	scanf("%ld",&ord.IntOrderNo);
	printf(">>>>>>>>Input Order prodCode: ");
	scanf("%s",&prodcode);
	strcpy(ord.ProdCode, strupr(prodcode));

	rc = SPAPI_DeleteOrder(&ord); //modif xiaolin 2012-12-20
	printf("rc %d \n",rc);
}

void SPDLLCALL ApiOrderRequestFailed(tinyint action, SPApiOrder *order, long err_code, char *err_msg)
{
	printf("\nOrder Request Failed:Order#%ld [%ld (%s)], Action=%d",order->IntOrderNo ,err_code, err_msg, action);
}


#pragma endregion

#pragma region Pos厥累  持倉

void PosCount()
{
int count;

	count = SPAPI_GetPosCount();
	printf("\n Acc: %s,Pos Count:%d", acc_no,count);
}

void GetPos()
{
int cnt, rc, i;
SPApiPos pos;

	cnt = SPAPI_GetPosCount();
	for (i = 0; i<cnt; i++)
	{
		rc = SPAPI_GetPos(i, &pos);
		if (rc == 0)
		{
			printf("\n ProdCode=%s,Prev.=%d @ %f,DayLong=%d @ %f,DayShort=%d @ %f, PLBaseCcy:%f, PL:%f, ExcRate:%f", pos.ProdCode, (pos.LongShort == 'B')?pos.Qty:-1*pos.Qty, pos.TotalAmt, pos.LongQty, pos.LongTotalAmt, pos.ShortQty, pos.ShortTotalAmt,pos.PLBaseCcy, pos.PL, pos.ExchangeRate);
		}
	}
	if (cnt == 0)
		printf("\n Acc: %s,Pos Count:0", acc_no);
}

void GetPosByProduct()
{
int rc;
SPApiPos pos;
char prodcode[16];

	memset(&pos, 0, sizeof(SPApiPos));
	printf("\n>>>>>>>>Input Pos ProdCode: ");	
	scanf("%s",&prodcode);
	printf("\n>>>>>>>>Query:%s Position.",prodcode);
	rc = SPAPI_GetPosByProduct(strupr(prodcode), &pos);
	if (rc == 0)
		printf("\n ProdCode=%s,Prev.=%d @ %f,DayLong=%d @ %f,DayShort=%d @ %f", pos.ProdCode, (pos.LongShort == 'B')?pos.Qty:-1*pos.Qty, pos.TotalAmt, pos.LongQty, pos.LongTotalAmt, pos.ShortQty, pos.ShortTotalAmt);
	else
		printf("\n No Product");
}

#pragma endregion

#pragma region Trade傖蝠暮翹  成交記錄

void TradeCount()
{
int count;

	count = SPAPI_GetTradeCount();
	printf("\n Acc: %s,Trade Count:%d", acc_no,count);

}

void GetTrade()
{
int cnt, rc, i;
SPApiTrade trade;

	cnt = SPAPI_GetTradeCount();
	for (i = 0; i<cnt; i++)
	{
		rc = SPAPI_GetTrade(i, &trade);
		if (rc == 0)
		{
			printf("\nOrder#%d, TradeNo:%lld,ProdCode=%s , B/S=%c , Qty=%d, Price=%f, ",trade.IntOrderNo, trade.TradeNo,  trade.ProdCode, trade.BuySell, trade.Qty, trade.Price);
		}
	}
	if (cnt == 0)
		printf("\n Acc: %s,Trade Count:0", acc_no);

}

void GetTradeByProduct()
{
int rc;
SPApiTrade trade;
long int_order_no;
bigint trade_no;

	memset(&trade, 0, sizeof(SPApiTrade));
	printf("\n>>>>>>>>Input Int Order No: ");	scanf("%u",&int_order_no);
	printf("\n>>>>>>>>Input Int Trade No: ");	scanf("%lld",&trade_no);
	rc = SPAPI_GetTradeByTradeNo(int_order_no, trade_no, &trade);
	if (rc == 0)
		printf("\n ProdCode=%s , B/S=%c , Qty=%d, Price=%f, ClOrderId=%s", trade.ProdCode, trade.BuySell, trade.Qty, trade.Price, trade.ClOrderId);
	else
		printf("\n No Trade Product");
}

#pragma endregion

#pragma region Price磁埮  合約

void SubscribeUninitPrice(int idx)
{
int rc;
char prodcode[16];

	
	printf("\n>>>>>>>>Input Price ProdCode: ");	
	scanf("%s",&prodcode); 
	if (idx == 1)
		printf("\n>>>>>>>>Subscribe Price prodCode: %s", prodcode);
	else
		printf("\n>>>>>>>>Uninit Price prodCode: %s", prodcode);

	rc = SPAPI_SubscribePrice(strupr(prodcode), idx); //idx, 0 :Uninit Price, 1:Subscribe Price, 2:set time to return to
}



void GetPriceCount()
{
int count;
	count = SPAPI_GetPriceCount();
	printf("\n Acc: %s,Price Count:%d", acc_no, count);

}

void GetPrice()
{
int cnt, i, rc, t, idx;
SPApiPrice price;

	printf("\n>>>>>>>> (1:all Price,0:by price idx)");			scanf("%d",&t);
	if(t == 1){
	cnt = SPAPI_GetPriceCount();
	for (i = 0; i < cnt; i++)
	{
		rc = SPAPI_GetPrice(i, &price);
		if (rc == 0)
		{
			printf("\n  ProdCode=%s , AskQty1=%d , Ask1=%f , Bid1=%f , BidQty1=%d  ", price.ProdCode, price.AskQty[0], price.Ask[0], price.Bid[0], price.BidQty[0]);
		}
	}
	if (cnt == 0)printf("\n No Subscribe Product");
	}
	else
	{
		printf("\n>>>>>>>> input price idx:");			scanf("%d",&idx);
		rc = SPAPI_GetPrice(idx, &price);
		if (rc == 0)
		{
			printf("\n  ProdCode=%s , AskQty1=%d , Ask1=%f , Bid1=%f , BidQty1=%d  ", price.ProdCode, price.AskQty[0], price.Ask[0], price.Bid[0], price.BidQty[0]);
		}
		else
		{
			printf("\n no price idx!(idx:%d)", idx);
		}
	}
}

void GetPriceByCode()
{
int  rc;
char prodcode[16];
SPApiPrice price;

	printf("\n>>>>>>>>Input Price ProdCode: ");	
	scanf("%s",&prodcode);

	printf("\n>>>>>>>>Price prodCode: %s", prodcode);
	rc = SPAPI_GetPriceByCode(strupr(prodcode), &price);    //悵痐磁埮眒扠 符夔鏽善歎 //保證合約已申請 才能拿到價
	if (rc == 0)
		printf("\n  ProdCode=%s , AskQty=%d , Ask=%f , Bid=%f , BidQty=%d  ", price.ProdCode, price.AskQty[0], price.Ask[0], price.Bid[0], price.BidQty[0]);
	else
		printf("\n No Subscribe Product:%d", rc);
}

void SPDLLCALL ApiPriceUpdate(SPApiPrice *price)
{
	printf("\nApi PriceUpdate:");
	printf(" Api ProdCode=%s", price->ProdCode);
	printf(" Api Bid=%Lf", price->Bid[0]);
	printf(" Api Qty=%u", price->BidQty[0]);
	printf(" Api Ask=%Lf", price->Ask[0]);
	printf(" Api Qty=%u", price->AskQty[0]);
	printf(" Last Time=%u", price->LastTime[0]);
}

/*void SPDLLCALL ProductListReady(int inst_cnt, int prod_cnt)
{
	printf("\n Product List Ready Acc: %s,Instrument Count:%d. Product Count:%d", acc_no, inst_cnt, prod_cnt);
}*/
void SPDLLCALL InstrumentListReply(bool is_ready, char *ret_msg)
{
	printf("\n Instrument Ready:%s. Ret Msg:%s",is_ready?"Ok":"No", ret_msg);
}

void SPDLLCALL ProductListReply(bool is_ready, char *ret_msg)
{
	printf("\n Product Ready:%s. Ret Msg:%s",is_ready?"Ok":"No", ret_msg);
}


void GetInstrument()
{
	int i,rc,count;
	SPApiInstrument instrument;

	count = SPAPI_GetInstrumentCount();
	printf("\n Acc: %s,Instrument Count:%d", acc_no, count);

	for (i = 0; i < count; i++)
	{
		rc = SPAPI_GetInstrument(i, &instrument);
		if (rc == 0)
		{
			printf("\n Number:%d, InstCode=%s, InstName=%s, Ccy=%s, Margin=%f",i+1, instrument.InstCode, instrument.InstName, instrument.Ccy, instrument.Margin);
		}
	}
	printf("\n Acc: %s,Instrument Count:%d", acc_no, count);
}

void GetInstrumentByCode()
{
int  rc;
char instCode[16];
SPApiInstrument instrument;

	printf("\n>>>>>>>>Input Instrument Code: ");	
	scanf("%s",&instCode);

	printf("\n>>>>>>>>Instrument Code: %s", instCode);
	rc = SPAPI_GetInstrumentByCode(strupr(instCode), &instrument);
	if (rc == 0)
		printf("\n MarketCode=%s , InstCode=%s , InstName=%s , Ccy=%s , Margin=%lf  ", instrument.MarketCode, instrument.InstCode, instrument.InstName, instrument.Ccy, instrument.Margin);
}

void GetProduct()
{
	int i,rc,count;
	SPApiProduct prod;

	count = SPAPI_GetProductCount();
	printf("\n Acc: %s,Product Count:%d", acc_no, count);

	for (i = 0; i < count; i++)
	{
		rc = SPAPI_GetProduct(i, &prod);
		if (rc == 0)
		{
			printf("\n Number:%d  ProdCode=%s , ProdName=%s , InstCode=%s ",i+1, prod.ProdCode, prod.ProdName, prod.InstCode);
		}
	}
	printf("\n Acc: %s,Product Count:%d", acc_no, count);
}

void GetProductByCode()
{
int  rc;
char prodCode[16];
SPApiProduct prod;

	printf("\n>>>>>>>>Input Product Code: ");	
	scanf("%s",&prodCode);

	printf("\n>>>>>>>>Product Code: %s", prodCode);
	rc = SPAPI_GetProductByCode(strupr(prodCode), &prod);
	if (rc == 0)
		printf("\n ProdCode=%s , ProdName=%s , InstCode=%s ", prod.ProdCode, prod.ProdName, prod.InstCode);
}

void LoadProductInfoListByCode()
{
	int rc;
	char prodCode[16];
	printf("\n>>>>>>>>Input Instrument Code: ");	
	scanf("%s",&prodCode);
	rc = SPAPI_LoadProductInfoListByCode(strupr(prodCode));
	printf("\nLoad Instrument Report Reply:%d ",rc);

}

void SPDLLCALL ProductListByCodeReply(char *inst_code, bool is_ready, char *ret_msg)
{
	printf("\n ProductListByCodeReply(inst code:%s):%s. Ret Msg:%s", inst_code, is_ready?"Ok":"No", ret_msg);
}

#pragma endregion

#pragma region Help堆翑  幫助


void HelpInfo()
{
	double dll_version;
	int rc;
	char ver_no[100], rel_no[100], suffix[100];
	rc = SPAPI_GetDllVersion(ver_no, rel_no, suffix);
	dll_version = SPAPI_GetDLLVersionDouble();

	printf("\n|------------------Help------------------|");
	printf("\n|   DLL Ver: %s                        |",ver_no);
	printf("\n|   Rel Ver: %s                        |",rel_no);
	printf("\n|   Dll Dat: %s                   |",suffix);
	printf("\n|   1:Order,  2:Pos,    3:Clear Trade    |");
	printf("\n|   4:Cash,   5:Price,  6:Ticker         |");
	printf("\n|   7:Login,  8:Logout, 9:Help           |");
	printf("\n|   0:Change Password,                   |");
	printf("\n|----------------------------------------|");
	
}

void HelpOrder()
{
	printf("\n|--------------Order Help----------------|");
	printf("\n|   G:Add,   F:Del,    D:Change          |");
	printf("\n|   S:LoadOrderReport  A:Get All Order   |");
	printf("\n|   X:SetOrderInactive  Q:Order Count    |"); 
	printf("\n|----------------------------------------|");
}

void HelpPos()
{
	printf("\n|----------------Pos Help----------------|");
	printf("\n|   H:Count,   J:All,   K:By Product     |");
	printf("\n|----------------------------------------|");
}

void HelpTrade()
{
	printf("\n|--------------Trade Help----------------|");
	printf("\n|   T:Count,   R:All,   E:By trade_no    |");
	printf("\n|   W:LoadTradeReport                    |");
	printf("\n|----------------------------------------|");
}

void HelpPrice()
{
	printf("\n|--------------Price Help----------------|");
	printf("\n|   Y:SubscribePrice, U:Count, I:By All  |");
	printf("\n|   O:Price By Code,  P:UninitPrice      |");
	printf("\n|   [:Load Instrument, L:Load ProductInfo|");
	printf("\n|   -:Load Product Info List By Code     |");
	printf("\n|   ]:Instrument Count And All,          |");
	printf("\n|   \\:Instrument By  Code,               |");
	printf("\n|   ;:Product Count And All,             |");
	printf("\n|   ':Product By  Code,                  |");
	printf("\n|   0:Market Count,  -:Market All        |");
	printf("\n|   =:Market By Code,                    |");
	printf("\n|----------------------------------------|");
}

void HelpTicker()
{
	printf("\n|--------------Ticker Help----------------|");
	printf("\n|    , :SubscribeTicker                   |");
	printf("\n|    . :UninitTicker                      |");
	printf("\n|-----------------------------------------|");
}

void HelpCash()
{
	printf("\n|---------------Cash Help-----------------|");
	printf("\n|    N:Acc Info      B:Acc Bal Count      |");
	printf("\n|    V:Acc All Bal   C:By Currency        |");
	printf("\n|    Z:Connection Status                  |");
	printf("\n|-----------------------------------------|");
}
#pragma endregion

#pragma region Ticker庈部傖蝠暮翹  市場成交記錄
void SubscribeTicker()
{
int rc;
char prodcode[16];

	printf("\n>>>>>>>>Input Ticker ProdCode: ");	
	scanf("%s",&prodcode);
	printf("\n>>>>>>>>Subscribe Ticker prodCode: %s", prodcode);
	rc = SPAPI_SubscribeTicker(strupr(prodcode), 1);
}

void UninitTicker()
{
int rc;
char prodcode[16];

	printf("\n>>>>>>>>Input Uninit Ticker ProdCode: ");	
	scanf("%s",&prodcode);
	printf("\n>>>>>>>>Uninit Ticker prodCode: %s", prodcode);
	rc = SPAPI_SubscribeTicker(strupr(prodcode), 0);
}

void SPDLLCALL TickerUpdate(SPApiTicker *ticker)
{
        struct tm *tblock;
        time_t TheTime = ticker->TickerTime;
        tblock = localtime(&TheTime);
		printf("\n ProdCode=%s, Price=%f, Qty=%d, TickerTime=%02d:%02d:%02d", ticker->ProdCode, ticker->Price, ticker->Qty, tblock->tm_hour, tblock->tm_min, tblock->tm_sec);
}

#pragma endregion

#pragma region User Login Logout蚚誧腎翹腎堤 用戶登錄登出

void Login()
{
	printf("\n:_______________________________________________:");
	printf("\n|======           SP API Login            ======|");
	printf("\n|_______________________________________________|");

	//port AE:8081, Client:8080
	printf("\n| [1] Host : ");			scanf("%s",host);
	printf("\n| [2] Port : ");			scanf("%hd",&port);
	printf("\n| [3] Acc No : ");		scanf("%s",acc_no);
	printf("\n| [4] User Id : ");		scanf("%s",user_id);
	printf("\n| [5] Password : ");		scanf("%s",password);
	printf("\n| [6] License : ");		scanf("%s",license);
	printf("\n| [7] App Id : ");		scanf("%s",app_id);

	SPAPI_SetLoginInfo(host,port,strupr(license),strupr(app_id),user_id,password);//9A9CC2D13C7A3615
	int i = SPAPI_Login();

}

void SPDLLCALL LoginReply(long ret_code, char *ret_msg)
{
	printf("\nLoginReply: Ret code %d, Ret msg %s", ret_code, (ret_code == 0)?"OK":ret_msg);
}

void Logout()
{
	SPAPI_Logout();
}

void SPDLLCALL LogoutReply(long ret_code, char *ret_msg)
{
	printf("\nLogoutReply: Ret code %d, Ret msg %s", ret_code, ret_msg);
}

void SPDLLCALL LoginStatusUpdate(long ret_status)
{
	switch(ret_status)
	{
		case 0:
			login_status = false; break;
		case 5:
			login_status = true; break;
	}
	printf("\n User Login Status: %ld, msg: %s.", ret_status, UserStatus(ret_status));
}

void SPDLLCALL AccInfoReply(char *acc_no, int max_bal, int max_pos, int max_order)
{
		printf("\nLogin AccInfo: acc_no: %s(max_bal:%d,max_pos:%d,max_order:%d.)", acc_no, max_bal,max_pos,max_order);
}

void GetConnectionStatus()
{
	int rc;
	int status_Id;
	printf("\n |-----------------------------|");
	printf("\n |  80:Transaction Link        |");
	printf("\n |  83:Price Link              |");
	printf("\n |  87:Long Depth Link         |");
	printf("\n |  88:Information Link        |");
	printf("\n |-----------------------------|");

	printf("\n>>>>>>>>Input Status ID: ");  scanf("%d",&status_Id);
	rc = SPAPI_GetLoginStatus(status_Id);
	printf("\n User Connection Status: %d, msg: %s.", rc, UserStatus(rc)); 
}

void SPDLLCALL PServerLinkStatusUpdate(short host_id, long con_status)
{
	char *host_name;
	switch(host_id)
	{
		case 80:
			host_name = "Transaction Link"; break;
		case 83:
			host_name = "Price Link"; break;
		case 87:
			host_name = "Long Depth Link"; break;
		case 88:
			host_name = "Information Link"; break;
	}
	printf("\n User Connection Status: %d,%s : %s.", host_id, host_name, UserStatus(con_status));
}

void SPDLLCALL ConnectionErrorUpdate(short host_id, long link_err)
{
	char *host_name;
	switch(host_id)
	{
		case 80:
			host_name = "Transaction Link"; break;
		case 83:
			host_name = "Price Link"; break;
		case 87:
			host_name = "Long Depth Link"; break;
		case 88:
			host_name = "Information Link"; break;
	}
	printf("\n Cannot Connect  To The Server: Error Code: %d, %s", link_err, host_name);
}


char *UserStatus(long status_id)
{
	char *msg = "";

	switch(status_id)
	{
		case 0:
			msg = "Closed";  break;
		case 1:
			msg = "Connecting"; break;
		case 2:
			msg = "Connected"; break;
		case 3:
			msg = "Connect_Error"; break;
		case 4:
			msg = "Logging_In"; break;
		case 5:
			msg = "Logged_In"; break;
		case 6:
			msg = "Logging_Out"; break;
		case 7:
			msg = "Logged_Out"; break;
		case 8:
			msg = "Login_Failed"; break;
		case 9:
			msg = "Connection_Lost"; break;
		case 10:
			msg = "Closing"; break;
		case 11:
			msg = "Host_Req"; break;
	}
	return msg;
}


void ChangePassword()
{
int rc;
char old_psw[16];
char new_psw[16];

	printf("\n>>>>>>>>Input old password: ");	scanf("%s",&old_psw);
	printf("\n>>>>>>>>Input new password: ");	scanf("%s",&new_psw);
	rc = SPAPI_ChangePassword(old_psw, new_psw);
	if (rc != 0)
		printf("\n>>>>>>>>Change password Error: rc:%d", rc);
}

void SPDLLCALL PswChangeReply(long ret_code, char *ret_msg)
{
	printf("\n User Change PassWord: code:%ld, msg: %s.", ret_code, ret_msg);
}

#pragma endregion

#pragma region Acc Info誧諳訧蹋  戶口資料

void GetAccInfo()
{
	SPApiAccInfo acc_info;
	int rc;

	memset(&acc_info, 0, sizeof(SPApiAccInfo));
	rc = SPAPI_GetAccInfo(&acc_info);
	if (rc == 0)
		printf("\nAccInfo: acc_no: %s  AE:%s  BaseCcy:%s,  MarginClass:%s, NAV:%f, BuyingPower:%f, CashBal:%f, MarginCall:%f, CommodityPL:%Lf, LockupAmt:%f", acc_info.AccName, acc_info.AEId, acc_info.BaseCcy, acc_info.MarginClass,acc_info.NAV,acc_info.BuyingPower,acc_info.CashBal,acc_info.MarginCall,acc_info.CommodityPL,acc_info.LockupAmt);
}

void GetAccBalCount()
{
	int count;

	count = SPAPI_GetAccBalCount();
	printf("\n Acc: %s,Acc Bal Count:%d", acc_no,count);
}

void GetAccBal()
{
int cnt, i, rc;
SPApiAccBal accBal;

	cnt = SPAPI_GetAccBalCount();
	for (i = 0; i < cnt; i++)
	{
		rc = SPAPI_GetAccBal(i, &accBal);
		if (rc == 0)
		{
			printf("\n  Ccy=%s , CashBf=%f , NotYetValue=%f , TodayCash=%f , TodayOut=%f,  Unpresented=%f ", accBal.Ccy, accBal.CashBf, accBal.NotYetValue, accBal.TodayCash, accBal.TodayOut, accBal.Unpresented);
		}
	}
}

void GetAccBalByCurrency()
{
SPApiAccBal accBal;
int rc;

	memset(&accBal, 0, sizeof(accBal));
	printf("\n>>>>>>>>Input Bal Ccy: ");	scanf("%s",&accBal.Ccy);
	rc = SPAPI_GetAccBalByCurrency(accBal.Ccy, &accBal);
	if (rc == 0)
	{
		printf("\n  Ccy=%s , CashBf=%f , NotYetValue=%f , TodayCash=%f , TodayOut=%f,  Unpresented=%f ", accBal.Ccy, accBal.CashBf, accBal.NotYetValue, accBal.TodayCash, accBal.TodayOut, accBal.Unpresented);
	}
	else
		printf("\nFind No Ccy!");
}
#pragma endregion


/*隆等隙覃源楊*/
void SPDLLCALL OrderReport(long rec_no, SPApiOrder *order)
{
	printf("\nOrder Report:Status:%s , Order#%ld, ProdCode=%s , Price=%Lf , Qty=%ld, TradedQty=%ld, TotalQty=%ld, ClOrderId=%s", 
  OutputOrderStatus(order->Status), order->IntOrderNo, order->ProdCode, order->Price, order->Qty, order->TradedQty, order->TotalQty, order->ClOrderId);
}

void SPDLLCALL TradeReport(long rec_no, SPApiTrade *trade)
{
	 struct tm *tblock;
	 time_t TheTime = trade->TradeTime;
     tblock = localtime(&TheTime);
	printf("\nTrade Report:Status:%s, Order#%ld , trade_no=%lld, trade_price=%lf, trade_qty=%ld, ClOrderId=%s, Time=%02d:%02d:%02d", OutputOrderStatus(trade->Status),trade->IntOrderNo, trade->TradeNo, trade->Price, trade->Qty, trade->ClOrderId, tblock->tm_hour, tblock->tm_min, tblock->tm_sec);
}

/*跦擂濬倰迵隆等袨怓樓婥隆等隙覃源楊*/
/*根據請求類型與訂單狀態加載訂單回調方法*/
void LoadOrderReport()
{
int rc;

	rc = SPAPI_LoadOrderReport(acc_no);
	printf("\nLoad Order Report Reply:%d ",rc);
}

/*跦擂濬倰樓婥傖蝠隙覃源楊*/
/*根據請求類型加載成交回調方法*/
void LoadTradeReport()
{
	int rc;

	rc = SPAPI_LoadTradeReport(acc_no);
	printf("\nLoad Trade Report Reply:%d ",rc);
}

void LoadInstrumentList()
{
	int rc;

	rc = SPAPI_LoadInstrumentList();
	printf("\nLoad Instrument Report Reply:%d ",rc);
}

void LoadProductInfoList()
{
	int rc;

	rc = SPAPI_LoadProductInfoList();
	printf("\nLoad ProductInfo Report Reply:%d ",rc);
}

//隆等袨怓陓洘
char *OutputOrderStatus(char status)
{
	switch(status)
	{
		case ORDSTAT_SENDING:		return"sending";
		case ORDSTAT_WORKING:		return"working";
		case ORDSTAT_INACTIVE:		return"inactive";
		case ORDSTAT_PENDING:		return"pending";
		case ORDSTAT_ADDING:		return"adding";
		case ORDSTAT_CHANGING:		return"changing";
		case ORDSTAT_DELETING:		return"deleting";
		case ORDSTAT_INACTING:		return"inacting";
		case ORDSTAT_PARTTRD_WRK:	return"parttrd_wrk";
		case ORDSTAT_TRADED:		return"traded";
		case ORDSTAT_DELETED:		return"deleted";
		case ORDSTAT_APPROVEWAIT:   return"approve wait";
		case ORDSTAT_TRADEDREP:		return"traded & reported";
		case ORDSTAT_DELETEDREP:	return"deleted & reported";
		case ORDSTAT_RESYNC_ABN:	return"resync abnormal";
		case ORDSTAT_PARTTRD_DEL:	return"partial traded & deleted";
		case ORDSTAT_PARTTRD_REP:	return"partial traded & reported (deleted)";
	}
	return "???";
}
