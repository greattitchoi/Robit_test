#students.csv
import csv

with open ("students.csv","w",newline="",encoding="utf-8") as file: #student.csv생성
    writer = csv.writer(file)

    writer.writerow(["name","score"])
    writer.writerows([["민준",85],["서연",92],["지우","abc"],["하늘",105],["유진",78]])

list_name=[]    #이름을 csv파일에서 읽어서 저장할 리스트
list_score=[]   #점수를 csv파일에서 읽어서 저장할 리스트
try:
    with open ("students.csv",newline="",encoding="utf-8") as file: #student.csv파일 읽기
        reader = csv.reader(file)
        header = next(reader)

        for row in reader:  #이름이랑 점수 저장 반복
            name = row[0]
            try:    #점수값이 정수형이 맞는지 예외처리하기
                score=int(row[1])
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
    writer = csv.writer(file)

    writer.writerow(["name","score"])
    for i in range(len(list_name)): #조건에 맞는 이름과 점수를 csv파일에 저장하기
        writer.writerow([list_name[i],list_score[i]])

summary={"인원수":len(list_name),"평균":sum(list_score)/len(list_score), "최고점":max(list_score)}  #json파일에 들어갈 인원수, 평균, 최고점 딕셔너리파일

import json
with open("summary.json","w",encoding="utf-8") as file: #json파일 생성하기
    json.dump(summary,file,ensure_ascii=False,indent=2)


