# elevator-prototype

## Introduction

### Title
| Name | elevator-prototype using arduino |
|:---|:---|
| Background | Challenges for Periodic Control and Understanding of Various Sequences Using Arduino

### Tech Stack
|Part|Technologies|
|---|---|
|Development<br/>Environment|<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=white"/> <img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=Ubuntu&logoColor=white"/>|
|Language|<img src="https://img.shields.io/badge/-C++-blue?logo=cplusplus"/> 
|Hardware|<img src="https://img.shields.io/badge/Arduino-00878F?logo=arduino&logoColor=fff&style=plastic"/> 
|Collaborative Tools| <img src="https://img.shields.io/badge/slack-4A154B?style=for-the-badge&logo=slack&logoColor=white"/> |

## 0. Research Background

### Understanding and Studying Periodic Control?

While studying Arduino, I thought at first that there would be no problem if I simply put Delay to control the robot's movement, but I was coding it in the wrong way. There is a big disadvantage in that it is impossible to perform other movements at the same time without periodic control. To study periodic control, I did this task by simply simulating an elevator prototype so that I could study why periodic control is necessary and get used to coding for periodic control.





## 1. 서비스를 위한 필요 데이터 수집

### 1-1. 사용자 요구사항 정의 (USER REQUIREMENTS)
우리는 배경조사를 통해 농장주(사용자)의 상황을 알게 되었습니다. <br/>
농장주의 현 상황을 바탕으로 요구사항을 정의해보았습니다. 
| No. | 요구사항 |
|:---:|---|
|UR_01|아래와 같은 농장 정보를 한눈에 모니터링 할 수 있게 해주세요. <br/>- 현재 총 돼지 수 <br/> - 월별 사료 급여량 <br/> - 월별 농장 운영비용 <br/> - 월별 수익 예측  |
|UR_02| 1년동안 엄마돼지 한마리가 출산하여 출하시킨 돼지 평균 마리 수를 알고 싶어요 <br/> (= MSY를 알고 싶어요) |
|UR_03|1년동안 엄마돼지 한마리가 출산하여 젖을 떼기까지 이어진 돼지 평균 마리 수를 알고 싶어요 <br/> (= PSY를 알고 싶어요)|
|UR_04|돼지가 교배후 분만으로 얼마나 이어졌는지 평균을 알고 싶어요. <br/> (= 분만율을 알고 싶어요)|
|UR_05|엄마돼지가 분만시 아기 돼지가 몇마리나 살아남았는지 평균을 알고 싶어요. <br/> (= 평균 실산을 알고 싶어요)|
|UR_06|우리 농장의 예상 사료 가격을 알려줬으면 좋겠어요.|
|UR_07|우리 농장의 예상 운영비를 알려줬으면 좋겠어요. <br/> 운영비에는 아래의 항목이 포함되었으면 좋겠어요. <br/> - 수도광열비, 농구비, 영농시설비, 기타재료비, 차입금이자, 토지임차료, 고용노동비, 분뇨처리비, 생산관리비, 기타비용, 총 합계|
|UR_08|우리 농장(혹은 앞으로 설립할 농장)이 월 얼마정도 수익이 나올지 계산해주었으면 좋겠어요. |

### 1-2. 시스템 요구사항 정의 (SYSTEM REQUIREMENTS)

시용자 요구사항을 바탕으로 시스템 요구사항을 정의해보았습니다.

| No. | 기능 이름 | 기능 설명 |
|:---:|---|---|
|SR_01|농장정보 <br/> 시각화 기능 <br> (대쉬보드) | 농장 정보를 직관적으로 파악할 수 있도록 시각화하여 제공 <br/> - 현재 총 돼지 수 <br/> - 월별 농장 운영비용 <br/> - 월별 수익 예측 <br/> - 월별 사료 급여량 <br/> - 출하 시기 추천
|SR_02|핵심 지표 <br/> 시각화 기능|농장 관리에 필요한 필수 지표 제공 <br/> - MSY : 엄마돼지 한마리가 출산하여 출하시킨 돼지 평균 마리 수 <br/> - PSY : 엄마돼지 한마리가 출산하여 젖을 떼기까지 이어진 돼지 평균 마리 수 <br/> - 분만율 : 돼지가 교배 후 분만으로 이어지는 비율 <br/> - 평균실산 : 돼지가 분만시 아기 돼지가 몇마리나 살아남았는지 평균|
|SR_03|사료비 <br/> 계산기| 농장규모에 따른 사료 비용 예측 |
|SR_04|운영비 <br/> 계산기|농장규모에 따른 운영 비용 예측 <br/> 운영 비용 목록 <br/> - 수도광열비(전기세), 영농시설비, 기타재료비, 차입금이자, 토지임차료, <br/> 고용노동비, 분뇨처리비, 생산관리비, 기타비용, 총 합계|
|SR_05|수익 <br/> 계산기|농장규모와 돼지 평균 무게에 따른 수익 예측|

### 1-3. 필요 데이터 다이어그램 만들기 (ER DIAGRAM)

![Image](https://github.com/user-attachments/assets/471bae27-944e-478f-8848-e11fd1fba4b6)

### 1-4. 수집 데이터 정리 (COLLECT)
시스템 요구사항을 바탕으로, 저희가 수집한 데이터와 저장된 DB 테이블명을 정리했습니다.
| SR No. | 기능 | 데이터 | DB 테이블 or 파일명 |
|:---:|---|---|---|
|SR_02_01| MSY 출력 | | |
|SR_02_02| PSY 출력 | 이유 두수 | avg_iyu |
|        |         | 모돈 회전율 | predicted_sow_turnover |
|SR_02_03| 분만율 출력 | 전국 평균 분만율 | pig_db_monthly |
|SR_02_04| 평균실산 출력 | 실 산자 수 | avg_san |
|SR_03_01| 사료비 계산 | 두 당 사료비 | feed |
|SR_04_01| 운영비 계산 | 두 당 운영비 | operating_price |
|SR_05_01| 수익 계산 | 두 당 돼지 도매가 | 파일 : pig_cost.ipynb |
|        |         | 두 당 돼지 순 이익 | profit_per_pig |




