#students.csv
import csv
rows=[{"name":"민준","score":85},{"name":"서연","score":92},{"name":"지우","score":"abc"},{"name":"하늘","score": 105},{"name":"유진","score":78}]
with open ("students.csv","w",newline="",encoding="utf-8") as file: #student.csv생성
    writer = csv.DictWriter(file,fieldnames=["name","score"])    #딕셔너리로 csv파일 생성하기

    writer.writeheader()
    writer.writerows(rows)

list_name=[]    #이름을 csv파일에서 읽어서 저장할 리스트
list_score=[]   #점수를 csv파일에서 읽어서 저장할 리스트
try:
    with open ("students.csv",newline="",encoding="utf-8") as file: #student.csv파일 읽기
        reader=csv.DictReader(file) #딕셔너리로 csv파일 읽어오기

        for row in reader:  #이름이랑 점수 저장 반복
            name = row["name"]
            try:    #점수값이 정수형이 맞는지 예외처리하기
                score=int(row["score"])
                if(0<=score<=100):  #점수가 0~100사이인지 판별하기
                    print(name, score)
                    list_name.append(name)
                    list_score.append(score)
                else: 
                    print("숫자범위를 초과했습니다.")
            except ValueError:
                print("ValueError")
except FileNotFoundError:
    print("FileNotFoundError")
        
with open ("clean_students.csv","w",newline="",encoding="utf-8") as file:   #clean_students.csv파일 생성하기
    writer = csv.DictWriter(file,fieldnames=["name","score"])    #딕셔너리로 csv파일 생성하기

    for i in range(len(list_name)): #조건에 맞는 이름과 점수를 csv파일에 생성하기
        writer.writerow({"name":list_name[i],"score":list_score[i]})

summary={"인원수":len(list_name),"평균":sum(list_score)/len(list_score), "최고점":max(list_score)}  #json파일에 들어갈 인원수, 평균, 최고점 딕셔너리파일

import json
with open("summary.json","w",encoding="utf-8") as file: #json파일 생성하기
    json.dump(summary,file,ensure_ascii=False,indent=2)


