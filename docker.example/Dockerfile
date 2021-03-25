# Use existing python image version 3.9
FROM python:3.9

# Create application directory and set working directory.
RUN mkdir -p /app
WORKDIR /app

# Copy and install the requirements.txt
COPY requirements.txt /app
RUN pip install -r /app/requirements.txt

# Copy the rest of the application.
COPY app.py /app/
COPY templates/ /app/templates/

# Set the default command to be gunicorn, WSGI HTTP server.
ENTRYPOINT ["/usr/local/bin/gunicorn"]
CMD ["--bind", "0.0.0.0:5000", "app:app"]
