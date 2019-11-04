from requests import *
from http import *
from selenium import *
import json
import time
session=session()
def spiderlagou(keyword,page):
    url="https://www.lagou.com/jobs/positionAjax.json?needAddtionalResult=false"

    Headers={'Referer': 'https://www.lagou.com/jobs/list_python%E7%88%AC%E8%99%AB?labelWords=&fromSearch=true&suginput=',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.70 Safari/537.36'

    }
    url1="https://www.lagou.com/jobs/list_python%E7%88%AC%E8%99%AB?labelWords=&fromSearch=true&suginput="

    session.get(url=url1,headers=Headers)

    data={}

    data['first']='true'
    data['pn']=page
    data['kd']=keyword

    resp=session.post(url,data=data,headers=Headers)

    return resp
def getcount(resp):
    resp = resp.json()
    totalCount=resp['content']['positionResult']['totalCount']
   # print(totalCount)
    return totalCount//15+1

def save_file(resp,A):
    all = []
    resp = resp.json()
    for i in range(15):
      try:
            positionName=resp['content']['positionResult']['result'][i]['positionName']
            companyFullName=resp['content']['positionResult']['result'][i]['companyFullName']
            city=resp['content']['positionResult']['result'][i]['city']
            companySize=resp['content']['positionResult']['result'][i]['companySize']
            education=resp['content']['positionResult']['result'][i]['education']
            salary=resp['content']['positionResult']['result'][i]['salary']

            all.append(positionName)
            all.append("    ")
            all.append(companyFullName)
            all.append("    ")
            all.append(salary)
            all.append("    ")
            all.append(city)
            all.append("    ")
            all.append(companySize)
            all.append("    ")
            all.append(education)
            all.append('\n                          -----------------------\n')
      except Exception as e:
           print(e)
           exit()


      A.writelines(all)

    return

if __name__=='__main__':
    keyword=input("请输入查找内容：")

    resp=spiderlagou(keyword,1)
    text_name='c:/py/'+str(keyword)+'LG.text'
    A = open(text_name, 'a')
    page=getcount(resp)

    print("共有%d页记录"%page)
    if page>30:
        page=30
    print("正在爬取....")
    for x in range(1,int(page)):
      resp = spiderlagou(keyword,x)
      save_file(resp,A)
      time.sleep(5)
    A.close()
