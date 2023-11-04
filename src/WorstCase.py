import pandas as pd
import plotly.express as px
import os
import plotly.graph_objects as go

path = "data/graphs"
if not os.path.exists(path):
    os.mkdir(path)

xAxis = "chaves"
yAxis = "operações"
graphTitle = "Pior Caso"

AVL = pd.read_csv('data/worstCaseAVL.csv')
B1 = pd.read_csv('data/worstCaseB1.csv')
B5 = pd.read_csv('data/worstCaseB5.csv')
B10 = pd.read_csv('data/worstCaseB10.csv')
Rubro = pd.read_csv('data/worstCaseRubroNegra.csv')

fig1 = px.line(AVL, x = xAxis, y = yAxis, title = graphTitle)
fig1.update_traces(line_color='purple', name='AVL', showlegend=True)

fig2 = px.line(B1, x = xAxis, y = yAxis, title = graphTitle)
fig2.update_traces(line_color='red', name='B1', showlegend=True)

fig3 = px.line(B5, x = xAxis, y = yAxis, title = graphTitle)
fig3.update_traces(line_color='green', name='B5', showlegend=True)

fig4 = px.line(B10, x = xAxis, y = yAxis, title = graphTitle)
fig4.update_traces(line_color='black', name='B10', showlegend=True)

fig5 = px.line(Rubro, x = xAxis, y = yAxis, title = graphTitle)
fig5.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)


allFig = go.Figure(data=fig1.data + fig2.data + fig3.data + fig4.data + fig5.data)

allFig.update_xaxes(title_text = xAxis)
allFig.update_yaxes(title_text = yAxis)
allFig.update_layout({
    'plot_bgcolor': 'rgba(255, 255, 255, 255)',
    'paper_bgcolor': 'rgba(255,255,255,255)'
})

allFig.show()
allFig.write_image(path + "/worstCase.svg")
