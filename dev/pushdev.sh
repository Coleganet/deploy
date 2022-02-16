docker login
docker image tag pool:v36 coleganet/pool:v36
docker push coleganet/pool:v36

#pushing Mysql Database
docker image tag mariadb:coleganet/pool:Sqlv11
docker push  coleganet/pool:Sqlv11
