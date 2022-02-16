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


ARG ssh_prv_key ARG ssh_pub_key RUN apt-get update && \
    apt-get install -y \
        git \
        openssh-server \
        libmysqlclient-dev
# Authorize SSH Host
RUN mkdir -p /root/.ssh && \
    chmod 0700 /root/.ssh && \
    ssh-keyscan github.com > /root/.ssh/known_hosts
# Add the keys and set permissions
RUN echo "$ssh_prv_key" > /root/.ssh/id_rsa && \
    echo "$ssh_pub_key" > /root/.ssh/id_rsa.pub && \
    chmod 600 /root/.ssh/id_rsa && \
    chmod 600 /root/.ssh/id_rsa.pub
# Avoid cache purge by adding requirements first
#ADD ./requirements.txt /app/requirements.txt WORKDIR 
#/app/ RUN pip install -r requirements.txt
# Remove SSH keys
RUN rm -rf /root/.ssh/
# Add the rest of the files
ARG ssh_pub_key RUN mkdir -p /root/.ssh \
    && chmod 0700 /root/.ssh \
    && passwd -u root \
    && echo "$ssh_pub_key" > /root/.ssh/authorized_keys \
    && apk add openrc openssh \
    && ssh-keygen -A \
    && echo -e "PasswordAuthentication no" >> /etc/ssh/sshd_config \
    && mkdir -p /run/openrc \
    && touch /run/openrc/softlevel WORKDIR /app COPY . . 
RUN yarn
RUN yarn build
RUN  -v /etc/ssl/certs -v /var/lib/mysql -v /etc/environment:/etc/environment -v /run/xtables.lock:/run/xtables.lock -v /var/run/docker.sock:/var/run/docker.sock
CMD /var/run/docker.sock:/var/run/docker.sock
CMD /run/xtables.lock:/run/xtables.lock
CMD /etc/ssh/sshd_config:/etc/ssh/sshd_config










ENTRYPOINT ["sh", "-c", "rc-status; rc-service sshd start; yarn start"]
