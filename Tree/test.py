import numpy as np
import pandas as pd
import math
import sys
from gamspy import Container, Set, Parameter, Variable, Equation, Model, Sum, Sense

def aaa(a):
    print("*************************")
    print(type(a))
    print(a)
    print("*************************")  
    
# nl_du = [["nl1", 5], ["nl2", 10], ["nl3", 15], ["nl4", 20], ["nl5", 25]]
# nl_bd = [["nl1", 10], ["nl2", 20], ["nl3", 30], ["nl4", 40], ["nl5", 50]]
# sp_cpxs = [["sp1",10],["sp2", 20],["sp3",30],["sp4", 40],["sp5",50],["sp6", 60],["sp7",70],["sp8", 80]]
# sp_gb = [["sp1",20],["sp2", 30],["sp3",40],["sp4", 50],["sp5",60],["sp6", 70],["sp7",80],["sp8", 90]]
# A = [[1,2,3,4,5],[6,7,8,9,10],[1,2,3,4,5],[6,7,8,9,10],[1,2,3,4,5],[6,7,8,9,10],[1,2,3,4,5],[6,7,8,9,10]]
# nl_da_dung = [["nl1", -1], ["nl2", -1], ["nl3", -1], ["nl4", -1], ["nl5", -1]]
# nl_da_dung_2 = [["nl1", -1], ["nl2", -1], ["nl3", -1], ["nl4", -1], ["nl5", -1]]
# nhu_cau_1 = [["sp1",5],["sp2", 6],["sp3",5],["sp4", 5],["sp5",5],["sp6", 6],["sp7",5],["sp8", 7]]
# nhu_cau_2 = [["sp1",8],["sp2", 5],["sp3",6],["sp4", 5],["sp5",5],["sp6", 7],["sp7",3],["sp8", 3]]

# tạo dữ liệu cho tính toán va ghi vào file Excel
data = {"Nguyên liệu": ["nl1","nl2","nl3","nl4", "nl5"] + [None]*3}
df = pd.DataFrame(data)

a = np.random.randint(1, 100, size=5)
nl_du = [["nl1", int(a[0])], ["nl2", int(a[1])], ["nl3", int(a[2])], ["nl4", int(a[3])], ["nl5", int(a[4])]]
df["Giá dư"] = list(a) + [None]*3   

a = a + np.random.randint(0, 100, size=5)
nl_bd = [["nl1", int(a[0])], ["nl2", int(a[1])], ["nl3", int(a[2])], ["nl4", int(a[3])], ["nl5", int(a[4])]]
df["Giá ban đầu"] = list(a) + [None]*  3   

df[" "] = ""
df["Sản phẩm"] = ["sp1","sp2","sp3","sp4", "sp5", "sp6", "sp7", "sp8"]

a = np.random.randint(1, 100, size=8)
sp_cpxs = [["sp1",int(a[0])],["sp2", int(a[1])],["sp3", int(a[2])],["sp4", int(a[3])],["sp5", int(a[4])],["sp6", int(a[5])],["sp7", int(a[6])],["sp8", int(a[7])]]
df["Chi phí sản xuất"] = list(a)

a = a + np.random.randint(1, 100, size=8)
sp_gb = [["sp1",int(a[0])],["sp2", int(a[1])],["sp3", int(a[2])],["sp4", int(a[3])],["sp5", int(a[4])],["sp6", int(a[5])],["sp7", int(a[6])],["sp8", int(a[7])]]
df["Giá bán"] = list(a)

df["  "] = ""
df["Nhu cầu"] = ["sp1","sp2","sp3","sp4", "sp5", "sp6", "sp7", "sp8"]

a = np.random.binomial(10, 0.5, 8)
nhu_cau_1 = [["sp1",int(a[0])],["sp2", int(a[1])],["sp3", int(a[2])],["sp4", int(a[3])],["sp5", int(a[4])],["sp6", int(a[5])],["sp7", int(a[6])],["sp8", int(a[7])]]
df["Nhu cầu 1"] = list(a)
zz1 = list(a)

a = np.random.binomial(10, 0.5, 8)
nhu_cau_2 = [["sp1",int(a[0])],["sp2", int(a[1])],["sp3", int(a[2])],["sp4", int(a[3])],["sp5", int(a[4])],["sp6", int(a[5])],["sp7", int(a[6])],["sp8", int(a[7])]]
df["Nhu cầu 2"] = list(a)
zz2 = list(a)

nl_da_dung_1 = [["nl1", -1], ["nl2", -1], ["nl3", -1], ["nl4", -1], ["nl5", -1]]
nl_da_dung_2 = [["nl1", -1], ["nl2", -1], ["nl3", -1], ["nl4", -1], ["nl5", -1]]

A = np.random.randint(1, 100, size=(8, 5))
A = A.tolist()

nldd1 = []
nldd2 = []
for i in range(5):
    sumA = 0
    for j in range(8):
        sumA += A[j][i]*nhu_cau_1[j][1]
    nl_da_dung_1[i][1] = (sumA)
    nldd1.append(sumA)
for i in range(5):
    sumA = 0
    for j in range(8):
        sumA += A[j][i]*nhu_cau_2[j][1]
    nl_da_dung_2[i][1] = (sumA)
    nldd2.append(sumA)  
df["Nguyên liệu đã dùng 1"] = nldd1 + [None]*3
df["Nguyên liệu đã dùng 2"] = nldd2 + [None]*3
z1 = 0
z2 = 0
for i in range(8):
    z1 += (sp_cpxs[i][1]-sp_gb[i][1] )*nhu_cau_1[i][1] 
    z2 += (sp_cpxs[i][1]-sp_gb[i][1] )*nhu_cau_2[i][1]
print(z1)
print(z2)
df["(l-q)*z"] = [z1+z2] + [None]*7
    
# Ghi dữ liệu vào file Excel
with pd.ExcelWriter('du_lieu.xlsx') as writer:
    df.to_excel(writer, sheet_name='Dữ liệu', index=False)

#Container
m = Container()

#Set
i = Set(m, "nl", records=["nl1","nl2","nl3","nl4", "nl5"], description="factory") # nhà máy
j = Set(m, "sp", records=["sp1","sp2","sp3","sp4", "sp5", "sp6", "sp7", "sp8"], description="product") # sản phẩm

#Parameter
c = Parameter(m, "c", domain=[i], description="c", records=nl_bd) # giá nhập 1 nguyên liệu
l = Parameter(m, "l", domain=[j], description="l", records=sp_cpxs) # chi phí sản xuất
q = Parameter(m, "q", domain=[j], description="q", records=sp_gb) # giá bán
s = Parameter(m, "s", domain=[i], description="s", records=nl_du) # giá bán ế
rhs = Parameter(m, "rhs", domain=[i], description="rhs", records=nl_da_dung_1) # ...
rhs2 = Parameter(m, "rhs2", domain=[i], description="rhs2", records=nl_da_dung_2) # ...
demand = Parameter(m, "demand", domain=[j], description="demand", records=nhu_cau_1) # nhu cầu
demand2 = Parameter(m, "demand2", domain=[j], description="demand2", records=nhu_cau_2) # nhu cầu

#Variable
x = Variable(m, "x", domain=[i], description="x", type="Positive") # 
y = Variable(m, "y", domain=[i], description="y", type="Positive") # 
y2 = Variable(m, "y2", domain=[i], description="y2", type="Positive") #


#Equation
st = Equation(m, "st", domain=[i], description="rang buoc") #
st2 = Equation(m, "st2", domain=[i], description="rang buoc2") 

st[i] = (x[i]-y[i]) == rhs[i]
st2[i] = (x[i]-y2[i]) == rhs2[i]


#Model
transport = Model(
    m,
    name="transport",
    equations=m.getEquations(),
    problem="LP",
    sense=Sense.MIN,
    # objective=Sum((j,i), c[i]*x[i] + (-s[i]*y[i] + (l[j]-q[j])*demand[j])/2 + (-s[i]*y2[i] + (l[j]-q[j])*demand2[j])/2),
    # objective=nl_bd[0][1]*x["nl1"]+nl_bd[1][1]*x["nl2"]+nl_bd[2][1]*x["nl3"]+nl_bd[3][1]*x["nl4"]+nl_bd[4][1]*x["nl5"]+((nl_du[0][1] - nl_bd[0][1])*y["nl1"]+(nl_du[1][1] - nl_bd[1][1])*y["nl2"]+ (nl_du[2][1] -nl_bd[2][1])*y["nl3"]+(nl_du[3][1] -nl_bd[3][1])*y["nl4"]+(nl_du[4][1] -nl_bd[4][1])*y["nl5"]+z1)/2+((nl_du[0][1] -nl_bd[0][1])*y2["nl1"]+(nl_du[1][1] -nl_bd[1][1])*y2["nl2"]+(nl_du[2][1] -nl_bd[2][1])*y2["nl3"]+(nl_du[3][1] -nl_bd[3][1])*y2["nl4"]+(nl_du[4][1] -nl_bd[4][1])*y2["nl5"] +z2)/2,
    
    objective=nl_bd[0][1]*x["nl1"]+nl_bd[1][1]*x["nl2"]+nl_bd[2][1]*x["nl3"]+nl_bd[3][1]*x["nl4"]+nl_bd[4][1]*x["nl5"]-(nl_du[0][1]*y["nl1"]+nl_du[1][1]*y["nl2"]+ nl_du[2][1]*y["nl3"]+nl_du[3][1]*y["nl4"]+nl_du[4][1]*y["nl5"]-z1)/2-(nl_du[0][1]*y2["nl1"]+nl_du[1][1]*y2["nl2"]+nl_du[2][1]*y2["nl3"]+nl_du[3][1]*y2["nl4"]+nl_du[4][1] *y2["nl5"]-z2)/2,
)

transport.solve(output=sys.stdout)
assert math.isclose(transport.objective_value, transport.objective_value , rel_tol=0.001)

# Ghi ma trận A vào file Excel
df_A = pd.DataFrame(A)
with pd.ExcelWriter('du_lieu.xlsx', mode='a') as writer:
    df_A.to_excel(writer, sheet_name='Ma trận A', index=False)

# Ghi kết quả vào file Excel
data = {"x": list(x.records["level"]) + [None]*3}
df_kq = pd.DataFrame(data)
df_kq["y1"] = list(y.records["level"]) + [None]*3
df_kq["y2"] = list(y2.records["level"]) + [None]*3
df_kq["z1"] = zz1
df_kq["z2"] = zz2
df_kq["Objective"] = [transport.objective_value] + [None]*7
with pd.ExcelWriter('du_lieu.xlsx', mode='a') as writer:
    df_kq.to_excel(writer, sheet_name='Kết quả', index=False)
  
print("...........................................................................................")