import pandas as pd
import plotly.express as px
import os
import plotly.graph_objects as go

path = "data/graphs"
if not os.path.exists(path):
    os.mkdir(path)

xAxis = "chaves"
yAxis = "operações"
graphTitle = "Caso Médio"
numberOfKeys = 1000
numberOfExecutions = 100

AVL = pd.read_csv('data/avgCaseAVL.csv')
B1 = pd.read_csv('data/avgCaseB1.csv')
B5 = pd.read_csv('data/avgCaseB5.csv')
B10 = pd.read_csv('data/avgCaseB10.csv')
Rubro = pd.read_csv('data/avgCaseRubroNegra.csv')

newAVL = pd.DataFrame(columns=[xAxis, yAxis])
newB1 = pd.DataFrame(columns=[xAxis, yAxis])
newB5 = pd.DataFrame(columns=[xAxis, yAxis])
newB10 = pd.DataFrame(columns=[xAxis, yAxis])
newRubro = pd.DataFrame(columns=[xAxis, yAxis])

for i in range(numberOfKeys):
    avgKey = AVL.loc[AVL[xAxis] == i, yAxis].sum() / numberOfExecutions
    newRow = pd.Series({xAxis: i, yAxis: avgKey})
    newAVL = pd.concat([newAVL, newRow.to_frame().T], ignore_index=True)

    avgKey = B1.loc[B1[xAxis] == i, yAxis].sum() / numberOfExecutions
    newRow = pd.Series({xAxis: i, yAxis: avgKey})
    newB1 = pd.concat([newB1, newRow.to_frame().T], ignore_index=True)

    avgKey = B5.loc[B5[xAxis] == i, yAxis].sum() / numberOfExecutions
    newRow = pd.Series({xAxis: i, yAxis: avgKey})
    newB5 = pd.concat([newB5, newRow.to_frame().T], ignore_index=True)

    avgKey = B10.loc[B10[xAxis] == i, yAxis].sum() / numberOfExecutions
    newRow = pd.Series({xAxis: i, yAxis: avgKey})
    newB10 = pd.concat([newB10, newRow.to_frame().T], ignore_index=True)

    avgKey = Rubro.loc[Rubro[xAxis] == i, yAxis].sum() / numberOfExecutions
    newRow = pd.Series({xAxis: i, yAxis: avgKey})
    newRubro = pd.concat([newRubro, newRow.to_frame().T], ignore_index=True)
   

fig1 = px.line(newAVL, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig1.update_traces(line_color='purple', name='AVL', showlegend=True)

fig2 = px.line(newB1, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig2.update_traces(line_color='red', name='B1', showlegend=True)

fig3 = px.line(newB5, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig3.update_traces(line_color='green', name='B5', showlegend=True)

fig4 = px.line(newB10, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig4.update_traces(line_color='black', name='B10', showlegend=True)

fig5 = px.line(newRubro, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig5.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)

allFig = go.Figure(data=fig2.data + fig1.data + fig3.data + fig4.data + fig5.data)

allFig.update_xaxes(title_text = xAxis)
allFig.update_yaxes(title_text = yAxis)
allFig.update_layout({
    'plot_bgcolor': 'rgba(255, 255, 255, 255)',
    'paper_bgcolor': 'rgba(255,255,255,255)'
})

allFig.show()
allFig.write_image(path + "/averageCase.svg")
