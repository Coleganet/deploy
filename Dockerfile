FROM coleganet/pool:v52

MAINTAINER JM pool@coleganet.com

#Add group to run the pool
RUN groupadd -r appool

#Create user for RUN
RUN useradd -g appool appool

#Set ownership and permissions
RUN chown -R appool:appool /app

#Swith user 
USER appool

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisor/conf.d/supervisord.conf"]
