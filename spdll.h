

#ifndef spapidll_def
#define spapidll_def

typedef char            tinyint;
typedef unsigned char   u_tinyint;
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
typedef __int64          bigint;
typedef unsigned __int64 u_bigint;

typedef char STR4[4];
typedef char STR16[16];
typedef char STR40[40];

#define ORD_BUY         'B'  		//鎗//買入
#define ORD_SELL        'S'			//闖堤//賣出
#define STOP_LOSS       'L'
#define STOP_UP         'U'
#define STOP_DOWN       'D'

#define AO_PRC          ((long)0x7fffffff)	//噥歎//競價

#define ORD_LIMIT       0			//癹歎//限價
#define ORD_AUCTION     2			//鼴闖歎//拍賣價
#define ORD_MARKET      6			//庈部歎//市場價

#define COND_NONE       0			//珨啜//一般
#define COND_STOP       1
#define COND_SCHEDTIME  3
#define COND_OCOSTOP    4
#define COND_TRAILSTOP  6
#define COND_COMBO_OPEN     8
#define COND_COMBO_CLOSE    9
#define COND_STOP_PRC       11
#define COND_OCOSTOP_PRC    14
#define COND_TRAILSTOP_PRC  16

#define VLD_REST_OF_DAY   0
#define VLD_FILL_AND_KILL 1
#define VLD_FILL_OR_KILL  2
#define VLD_UNTIL_EXPIRE  3
#define VLD_SPEC_TIME     4

#define ACT_ADD_ORDER    1				// 崝樓隆等// 增加訂單
#define ACT_CHANGE_ORDER 2				// 党蜊隆等// 修改訂單
#define ACT_DELETE_ORDER 3				// 刉壺隆等// 刪除訂單

/*隆等袨怓*/
#define ORDSTAT_SENDING     0			// 楷冞笢// 發送中
#define ORDSTAT_WORKING     1			// 馱釬笢// 工作中
#define ORDSTAT_INACTIVE    2			// 拸虴// 無效
#define ORDSTAT_PENDING     3			// 渾隅// 待定
#define ORDSTAT_ADDING      4			// 崝樓笢// 增加中
#define ORDSTAT_CHANGING    5			// 党蜊笢// 修改中
#define ORDSTAT_DELETING    6			// 刉壺笢// 刪除中
#define ORDSTAT_INACTING    7			// 拸虴笢// 無效中
#define ORDSTAT_PARTTRD_WRK 8			// 窒煦眒傖蝠甜遜婓馱釬笢// 部分已成交並且還在工作中
#define ORDSTAT_TRADED      9			// 眒傖蝠// 已成交
#define ORDSTAT_DELETED     10			// 眒刉壺// 已刪除
#define ORDSTAT_APPROVEWAIT 18			// 脹渾蠶袧 //approve wait
#define ORDSTAT_TRADEDREP   20			// traded & reported
#define ORDSTAT_DELETEDREP  21			// deleted & reported
#define ORDSTAT_RESYNC_ABN  24			// resync abnormal
#define ORDSTAT_PARTTRD_DEL 28			// partial traded & deleted
#define ORDSTAT_PARTTRD_REP 29			// partial traded & reported (deleted)

#define OC_DEFAULT              '\0'
#define OC_OPEN                 'O'
#define OC_CLOSE                'C'
#define OC_MANDATORY_CLOSE      'M'

#define REQMODE_UNSUBSCRIBE     0		//楷冞蛁秏眒隆堐耀宒//發送請求注消已訂閱模式
#define REQMODE_SUBSCRIBE       1		//楷冞隆堐耀宒//發送訂閱模式
#define REQMODE_SNAPSHOT        2		//蜆隆堐硐隙覃珨棒//該訂閱只回調一次

#define SP_MAX_DEPTH    20
#define SP_MAX_LAST     20

#define TBSTAT_WORK             1		//馱釬笢隆等袨怓//工作中訂單狀態
#define TBSTAT_PARTIAL          2		//窒煦傖蝠隆等袨怓//部分成交訂單狀態

#define LDREQ_LOAD              4		//楷冞樓婥濬倰//發送請求加載類型
#define LDREQ_UPDATE            8		//楷冞載陔濬倰//發送請求更新類型
#define LDREQ_LOAD_AND_UPD      12		//楷冞樓婥迵載陔濬倰//發送請求加載與更新類型

typedef struct
{
    long Qty;                    //奻累弇 //上日倉位 
    long DepQty;                 //湔揣累弇 //存儲倉位  
    long LongQty;                //踏酗累 //今日長倉 
    long ShortQty;               //踏傻累 //今日短倉 
    double TotalAmt;             //奻傖蝠 //上日成交 
    double DepTotalAmt;          //奻厥累軞杅(杅講*歎跡) //上日持倉總數(數量*價格) 
    double LongTotalAmt;         //踏酗累軞杅(杅講*歎跡) //今日長倉總數(數量*價格) 
    double ShortTotalAmt;        //踏傻累軞杅(杅講*歎跡) //今日短倉總數(數量*價格) 
	double PLBaseCcy;            //荅鋸(價掛億啟)
	double PL;                   //荅鋸
    double ExchangeRate;         //颯薹
    STR16 AccNo;                 //蚚誧//用戶 
    STR16 ProdCode;              //磁埮測鎢 //合約代碼 
    char LongShort;              //奻厥累鎗闖源砃 //上日持倉買賣方向 
    tinyint DecInPrice;          //苤杅萸 //小數點 
} SPApiPos;

typedef struct
{
    double Price;              //歎跡 //價格 
    double StopLevel;          //砦囷歎跡 //止損價格 
    double UpLevel;            //奻癹阨 //上限水平 
    double UpPrice;            //奻癹歎跡 //上限價格 
    double DownLevel;          //狟癹阨 //下限水平 
    double DownPrice;          //狟癹歎跡 //下限價格 
    bigint ExtOrderNo;         //俋窒硌尨 //外部指示 
    long IntOrderNo;           //蚚誧隆等晤瘍 //用戶訂單編號 
    long Qty;                  //呁狟講 //剩下數量
    long TradedQty;            //眒傖蝠杅講 //已成交數量 
    long TotalQty;             //隆等軞杅講//訂單總數量 2012-12-20 xiaolin
    long ValidTime;            //衄虴奀潔 //有效時間 
    long SchedTime;            //啎隆楷冞奀潔 //預訂發送時間 丁
    long TimeStamp;            //督昢諉彶隆等奀潔 //服務器接收訂單時間 
    u_long OrderOptions;       //彆蜆磁埮盓厥彶庈綴億蝠眢奀僇(T+1),褫蔚森扽俶扢峈:1 //如果該合約支持收市後期貨交易時段(T+1),可將此屬性設為:1 
    STR16 AccNo;               //蚚誧梛瘍 //用戶帳號 
    STR16 ProdCode;            //磁埮測瘍 //合約代號 
    STR16 Initiator;           //狟等蚚誧 //下單用戶  
    STR16 Ref;                 //統蕉 //參考 
    STR16 Ref2;                //統蕉2 //參考2 
    STR16 GatewayCode;         //厙壽 //網關 
    STR40 ClOrderId;           //蚚誧赻隅隆等統蕉//用戶自定訂單參考 2012-12-20 xiaolin
    char BuySell;              //鎗闖源砃 //買賣方向 
    char StopType;             //砦囷濬倰 //止損類型  
    char OpenClose;            //羲累 //開平倉  
    tinyint CondType;          //隆等沭璃濬倰 //訂單條件類型 
    tinyint OrderType;         //隆等濬倰 //訂單類型  
    tinyint ValidType;         //隆等衄虴濬倰 //訂單有效類型 
    tinyint Status;            //袨怓 //狀態 
    tinyint DecInPrice;        //磁埮苤杅弇 //合約小數位 
} SPApiOrder;

typedef struct
{
    double Price;              //傖蝠歎跡 //成交價格
    bigint TradeNo;            //傖蝠晤瘍 //成交編號
    bigint ExtOrderNo;         //俋窒硌尨 //外部指示
    long IntOrderNo;           //蚚誧隆等晤瘍 //用戶訂單編號
    long Qty;                  //傖蝠杅講 //成交數量
    long TradeDate;            //傖蝠 //成交日期
    long TradeTime;            //傖蝠奀潔 //成交時間
    STR16 AccNo;               //蚚誧 //用戶
    STR16 ProdCode;            //磁埮測鎢 //合約代碼
    STR16 Initiator;           //狟等蚚誧 //下單用戶
    STR16 Ref;                 //統蕉 //參考
    STR16 Ref2;                //統蕉2 //參考2
    STR16 GatewayCode;         //厙壽 //網關
    STR40 ClOrderId;           //蚚誧赻隅隆等統蕉//用戶自定訂單參考 2012-12-20 xiaolin
    char BuySell;              //鎗闖源砃 //買賣方向
    char OpenClose;            //羲累 //開平倉
    tinyint Status;            //袨怓 //狀態
    tinyint DecInPrice;        //苤杅弇 //小數位
} SPApiTrade;


typedef struct
{
    double Margin;			//悵痐踢//保證金
    long ContractSize;		//磁埮歎硉//合約價值
    STR16 MarketCode;		//蝠眢垀測鎢 //市場代碼
    STR16 InstCode;			//莉炵蹈測鎢 //產品系列代碼
    STR40 InstName;			//荎恅靡備 //英文名稱
    STR40 InstName1;		//楛极靡備 //繁體名稱
    STR40 InstName2;		//潠极靡備 //簡體名稱
    STR4 Ccy;				//莉炵蹈腔蝠眢啟笱 //產品系列的交易幣種
    char DecInPrice;		//莉炵蹈腔苤杅弇 //產品系列的小數位
    char InstType;			//莉炵蹈腔濬倰 //產品系列的類型
} SPApiInstrument;

typedef struct
{
   STR16 ProdCode;			//莉測鎢 //產品代碼
   char ProdType;			//莉濬倰 //產品類型
   STR40 ProdName;			//莉荎恅靡備 //產品英文名稱
   STR16 Underlying;		//壽薊腔億磁埮//關聯的期貨合約
   STR16 InstCode;			//莉炵蹈靡備 //產品系列名稱
   long ExpiryDate;			//莉善奀潔 //產品到期時間
   char CallPut;			//源砃劃迵嘗 //期權方向認購與認沽
   long Strike;				//俴妏歎//期權行使價
   long LotSize;			//忒杅//手數
   STR40 ProdName1;			//莉楛极靡備 //產品繁體名稱
   STR40 ProdName2;			//莉潠极靡備 //產品簡體名稱
   char OptStyle;			//腔濬倰//期權的類型
   long TickSize;			//莉歎跡郔苤曹趙弇杅//產品價格最小變化位數
}SPApiProduct;

typedef struct
{
    double Bid[SP_MAX_DEPTH];     //鎗歎 //買入價
    long BidQty[SP_MAX_DEPTH];    //鎗講 //買入量
    long BidTicket[SP_MAX_DEPTH]; //鎗硌鍔杅講 //買指令數量
    double Ask[SP_MAX_DEPTH];     //闖堤歎 //賣出價
    long AskQty[SP_MAX_DEPTH];    //闖堤講 //賣出量
    long AskTicket[SP_MAX_DEPTH]; //闖硌鍔杅講 //賣指令數量
    double Last[SP_MAX_LAST];     //傖蝠歎 //成交價
    long LastQty[SP_MAX_LAST];    //傖蝠杅講 //成交數量
    long LastTime[SP_MAX_LAST];   //傖蝠奀潔 //成交時間
    double Equil;                 //算歎 //平衡價
    double Open;                  //羲攫歎 //開盤價
    double High;                  //郔詢歎 //最高價
    double Low;                   //郔腴歎 //最低價
    double Close;                 //彶攫歎 //收盤價
    long CloseDate;               //彶庈 //收市日期
    double TurnoverVol;           //軞傖蝠講 //總成交量
    double TurnoverAmt;           //軞傖蝠塗 //總成交額
    long OpenInt;                 //帤累 //未平倉
    STR16 ProdCode;               //磁埮測鎢 //合約代碼
    STR40 ProdName;               //磁埮靡備 //合約名稱
    char DecInPrice;              //磁埮苤杅弇 //合約小數位
} SPApiPrice;

typedef struct
{
    double Price;              //歎跡 //價格
    long Qty;                  //傖蝠講 //成交量
    long TickerTime;           //奀潔 //時間
    long DealSrc;              //懂埭 //來源
    STR16 ProdCode;            //磁埮測鎢 //合約代碼
    char DecInPrice;           //苤杅弇 //小數位
} SPApiTicker;

typedef struct
{
	double NAV;               // 訧莉噱硉				//add xiaolin 2013-03-19
    double BuyingPower;       // 劃鎗薯					//add xiaolin 2013-03-19
    double CashBal;           // 珋踢賦豻				//add xiaolin 2013-03-19
	double MarginCall;        //袚彶踢塗
    double CommodityPL;       //妀荅鋸
    double LockupAmt;         //雲賦踢塗
    double CreditLimit;       //陓湃癹塗 // 信貸限額
    double MaxMargin;         //郔詢悵痐踢 // 最高保証金//modif xiaolin 2012-12-20 TradeLimit
    double MaxLoanLimit;      //郔詢質湃奻癹 // 最高借貸上限
    double TradingLimit;      //陓蚚蝠眢謞 // 信用交易額
    double RawMargin;         //埻宎悵聃踢 // 原始保證金
    double IMargin;           //價掛悵偩踢 //  基本保証金
    double MMargin;           //鋤厥悵偩踢 // 維持保証金
    double TodayTrans;        //蝠眢踢謞 // 交易金額
    double LoanLimit;         //聃褫偌?硉 // 證券可按總值
    double TotalFee;          //愐蚚?謞 //  費用總額
    STR16 AccName;            //諳靡想 //  戶口名稱
    STR4 BaseCcy;             //價掛? // 基本貨幣
    STR16 MarginClass;        //悵偩踢? // 保証金類別
    STR16 TradeClass;         //蝠眢? // 交易類別
    STR16 ClientId;           //諦 // 客戶
    STR16 AEId;               //?廢 //  經紀
    char AccType;             //諳? // 戶口類別
    char CtrlLevel;           //諷秶? //  控制級數
    char Active;              //汜虴 //  生效
    char MarginPeriod;        //僇 // 時段
} SPApiAccInfo;

typedef struct
{
    double CashBf;          //奻賦豻 //上日結餘
    double TodayCash;       //踏湔 //今日存取
    double NotYetValue;     //帤蝠彶 //未交收
    double Unpresented;     //帤募珋 //未兌現
    double TodayOut;        //枑猁 //提取要求
    STR4 Ccy;               //億啟 //貨幣
} SPApiAccBal;

#define SPDLLCALL __stdcall
/*隙覃源楊*/
typedef void (SPDLLCALL *LoginReplyAddr)(long ret_code, char *ret_msg);
typedef void (SPDLLCALL *LogoutReplyAddr)(long ret_code, char *ret_msg);
typedef void (SPDLLCALL *LoginStatusUpdateAddr)(long login_status);
typedef void (SPDLLCALL *LoginAccInfoAddr)(char *acc_no, int max_bal, int max_pos, int max_order);
typedef void (SPDLLCALL *ApiOrderRequestFailedAddr)(tinyint action, SPApiOrder *order, long err_code, char *err_msg);
typedef void (SPDLLCALL *ApiOrderReportAddr)(long rec_no, SPApiOrder *order);
typedef void (SPDLLCALL *ApiTradeReportAddr)(long rec_no, SPApiTrade *trade);
typedef void (SPDLLCALL *ApiPriceUpdateAddr)(SPApiPrice *price);
typedef void (SPDLLCALL *ApiTickerUpdateAddr)(SPApiTicker *ticker);
typedef void (SPDLLCALL *PServerLinkStatusUpdateAddr)(short host_id, long con_status);
typedef void (SPDLLCALL *ConnectionErrorAddr)(short host_id, long link_err);
typedef void (SPDLLCALL *InstrumentListReplyAddr)(bool is_ready, char *ret_msg);
typedef void (SPDLLCALL *ProductListReplyAddr)(bool is_ready, char *ret_msg);
typedef void (SPDLLCALL *PswChangeReplyAddr)(long ret_code, char *ret_msg);  //add xiaolin 2013-03-19
typedef void (SPDLLCALL *ProductListByCodeReplyAddr)(char *inst_code, bool is_ready, char *ret_msg);//add 2013-04-25

typedef void (SPDLLCALL *p_SPAPI_RegisterLoginReply)(LoginReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterLogoutReply)(LogoutReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterLoginStatusUpdate)(LoginStatusUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterLoginAccInfo)(LoginAccInfoAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterOrderRequestFailed)(ApiOrderRequestFailedAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterOrderReport)(ApiOrderReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterTradeReport)(ApiTradeReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterApiPriceUpdate)(ApiPriceUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterTickerUpdate)(ApiTickerUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterPServerLinkStatusUpdate)(PServerLinkStatusUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterConnectionErrorUpdate)(ConnectionErrorAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterProductListReply)(ProductListReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterInstrumentListReply)(InstrumentListReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterPswChangeReply)(PswChangeReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterProductListByCodeReply)(ProductListByCodeReplyAddr addr);

/*源楊*/
typedef double (SPDLLCALL *p_SPAPI_GetDLLVersion)();
typedef int    (SPDLLCALL *p_SPAPI_Initialize)();
typedef int    (SPDLLCALL *p_SPAPI_Uninitialize)();
typedef void   (SPDLLCALL *p_SPAPI_Poll)();
typedef void   (SPDLLCALL *p_SPAPI_SetBackgroundPoll)(bool onoff);
typedef void   (SPDLLCALL *p_SPAPI_SetLoginInfo)(char *host, int port, char *license, char *app_id, char *user_id, char *password);
typedef int    (SPDLLCALL *p_SPAPI_Login)();
typedef int    (SPDLLCALL *p_SPAPI_Logout)();
typedef int    (SPDLLCALL *p_SPAPI_GetLoginStatus)(short host_id);

typedef int (SPDLLCALL *p_SPAPI_AddOrder)(SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_ChangeOrder)(SPApiOrder *order, double org_price, long org_qty);
typedef int (SPDLLCALL *p_SPAPI_DeleteOrder)(SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_ActivateOrder)(SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_InactivateOrder)(SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_GetOrderCount)();
typedef int (SPDLLCALL *p_SPAPI_GetOrder)(int idx, SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_GetOrderByOrderNo)(long int_order_no, SPApiOrder *order);

typedef int (SPDLLCALL *p_SPAPI_GetPosCount)();
typedef int (SPDLLCALL *p_SPAPI_GetPos)(int idx, SPApiPos *pos);
typedef int (SPDLLCALL *p_SPAPI_GetPosByProduct)(char *prod_code, SPApiPos *pos);
typedef int (SPDLLCALL *p_SPAPI_GetTradeCount)();
typedef int (SPDLLCALL *p_SPAPI_GetTrade)(int idx, SPApiTrade *trade);
typedef int (SPDLLCALL *p_SPAPI_GetTradeByTradeNo)(long int_order_no, bigint trade_no, SPApiTrade *trade);

typedef int (SPDLLCALL *p_SPAPI_SubscribePrice)(char *prod_code, int mode);
typedef int (SPDLLCALL *p_SPAPI_GetPriceCount)();
typedef int (SPDLLCALL *p_SPAPI_GetPrice)(int idx, SPApiPrice *price);
typedef int (SPDLLCALL *p_SPAPI_GetPriceByCode)(char *prod_code, SPApiPrice *price);

typedef int (SPDLLCALL *p_SPAPI_GetInstrumentCount)();
typedef int (SPDLLCALL *p_SPAPI_GetInstrument)(int idx, SPApiInstrument *inst);
typedef int (SPDLLCALL *p_SPAPI_GetInstrumentByCode)(char *inst_code, SPApiInstrument *inst);
typedef int (SPDLLCALL *p_SPAPI_GetProductCount)();
typedef int (SPDLLCALL *p_SPAPI_GetProduct)(int idx, SPApiProduct *prod);
typedef int (SPDLLCALL *p_SPAPI_GetProductByCode)(char *prod_code, SPApiProduct *prod);

typedef int (SPDLLCALL *p_SPAPI_SubscribeTicker)(char *prod_code, int mode);
typedef int (SPDLLCALL *p_SPAPI_GetAccInfo)(SPApiAccInfo *acc_info);
typedef int (SPDLLCALL *p_SPAPI_GetAccBalCount)();
typedef int (SPDLLCALL *p_SPAPI_GetAccBal)(int idx, SPApiAccBal *acc_bal);
typedef int (SPDLLCALL *p_SPAPI_GetAccBalByCurrency)(char *ccy, SPApiAccBal *acc_bal);
typedef int (SPDLLCALL *p_SPAPI_GetDllVersion)(char *dll_ver_no, char *dll_rel_no, char *dll_suffix);

typedef int (SPDLLCALL *p_SPAPI_LoadOrderReport)(char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_LoadTradeReport)(char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_LoadInstrumentList)();
typedef int (SPDLLCALL *p_SPAPI_LoadProductInfoList)();
typedef int (SPDLLCALL *p_SPAPI_LoadProductInfoListByCode)(char *inst_code);//add 2013-04-25

typedef int (SPDLLCALL *p_SPAPI_ChangePassword)(char *old_psw, char *new_psw); //add xiaolin 2013-03-19
#endif

